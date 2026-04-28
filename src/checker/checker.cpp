#include "../../include/checker/checker.hpp"

#include <utility>

using namespace std;

namespace {
struct ScopeGuard {
    Checker& checker;
    explicit ScopeGuard(Checker& c) : checker(c) {}
    ~ScopeGuard() = default;
};

static TYPE parseBaseType(ASTNode* node) {
    if (!node) return VOID_TYPE;
    if (node->value == "int") return INT_TYPE;
    if (node->value == "float") return FLOAT_TYPE;
    return VOID_TYPE;
}

static int countArrayDims(ASTNode* node) {
    if (!node || node->name != "ArrayDims") return 0;
    int dim = 0;
    for (auto* child : node->children) {
        if (!child) continue;
        if (child->name == "ArrayDims") dim += countArrayDims(child);
        else ++dim;
    }
    return dim;
}

static TypeInfo buildType(TYPE base, int dim) {
    return TypeInfo{base, dim > 0, dim};
}

static bool sameTypeExact(const TypeInfo& a, const TypeInfo& b) {
    return a.baseType == b.baseType && a.isArray == b.isArray && a.arrayDim == b.arrayDim;
}

static bool isNumericType(const TypeInfo& type) {
    return !type.isArray && (type.baseType == INT_TYPE || type.baseType == FLOAT_TYPE);
}

static bool isIntType(const TypeInfo& type) {
    return !type.isArray && type.baseType == INT_TYPE;
}

static ASTNode* child(ASTNode* node, size_t index) {
    return node && index < node->children.size() ? node->children[index] : nullptr;
}
} // namespace

Checker::Checker(ErrReporter& reporter) : reporter_(reporter) {}

void Checker::check(ASTNode* root) {
    if (!root) return;
    pushScope();
    checkCompUnit(root);
    popScope();
}

void Checker::pushScope() { scopes_.emplace_back(); }

void Checker::popScope() {
    if (!scopes_.empty()) scopes_.pop_back();
}

bool Checker::declareSymbol(const string& name, const Symbol& symbol) {
    if (scopes_.empty()) pushScope();
    auto& scope = scopes_.back();
    if (scope.count(name)) return false;
    scope[name] = symbol;
    return true;
}

const Checker::Symbol* Checker::lookupSymbol(const string& name) const {
    for (auto it = scopes_.rbegin(); it != scopes_.rend(); ++it) {
        auto found = it->find(name);
        if (found != it->end()) return &found->second;
    }
    return nullptr;
}

FunctionInfo* Checker::lookupFunction(const string& name) {
    auto it = functions_.find(name);
    return it == functions_.end() ? nullptr : &it->second;
}

const FunctionInfo* Checker::lookupFunction(const string& name) const {
    auto it = functions_.find(name);
    return it == functions_.end() ? nullptr : &it->second;
}

void Checker::report(const string& message, ASTNode* node) const {
    reporter_.report(nodeLine(node), message);
}

int Checker::nodeLine(ASTNode* node) {
    return node ? node->line : 0;
}

TypeInfo Checker::makeType(TYPE baseType, bool isArray, int dim) {
    return TypeInfo{baseType, isArray, dim};
}

string Checker::typeName(const TypeInfo& type) {
    string name = type.baseType == INT_TYPE ? "int" : type.baseType == FLOAT_TYPE ? "float" : "void";
    for (int i = 0; i < type.arrayDim; ++i) name += "[]";
    return name;
}

bool Checker::sameType(const TypeInfo& a, const TypeInfo& b) {
    return sameTypeExact(a, b);
}

bool Checker::isIntLike(const TypeInfo& type) { return isIntType(type); }

bool Checker::isNumeric(const TypeInfo& type) { return isNumericType(type); }

bool Checker::isVoid(const TypeInfo& type) { return !type.isArray && type.baseType == VOID_TYPE; }

bool Checker::isIntNumber(ASTNode* node) { return node && node->name == "Int"; }

bool Checker::isFloatNumber(ASTNode* node) { return node && node->name == "Float"; }

ASTNode* Checker::child(ASTNode* node, size_t index) {
    return ::child(node, index);
}

void Checker::checkCompUnit(ASTNode* node) {
    if (!node) return;
    if (node->name == "CompUnit" || node->name == "ExtDefList" || node->name == "BlockItems") {
        for (auto* item : node->children) {
            if (!item) continue;
            checkCompUnit(item);
        }
        return;
    }
    if (node->name == "VarDecl") {
        checkDecl(node);
        return;
    }
    if (node->name == "FuncDef") {
        checkFuncDef(node);
        return;
    }
}

void Checker::checkDecl(ASTNode* node) {
    if (!node || node->name != "VarDecl") return;

    auto* typeNode = child(node, 0);
    auto* listNode = child(node, 1);
    TYPE baseType = parseBaseType(typeNode);
    if (!listNode) return;

    auto handleVarDef = [&](ASTNode* defNode) {
        if (!defNode) return;
        auto* varNode = defNode->name == "InitVar" ? child(defNode, 0) : defNode;
        auto* initNode = defNode->name == "InitVar" ? child(defNode, 1) : nullptr;
        if (!varNode || (varNode->name != "Var" && varNode->name != "Name")) return;

        int dim = countArrayDims(child(varNode, 0));
        TypeInfo type = buildType(baseType, dim);
        if (!declareSymbol(varNode->value, Symbol{type, false})) {
            report("Redefined Variable \"" + varNode->value + "\"", varNode);
        }

        if (initNode) {
            auto initType = evalExpr(initNode);
            if (initType.type.baseType == VOID_TYPE || initType.type.isArray) {
                report("Func return type not match", initNode);
            }
        }
    };

    if (listNode->name == "VarDefList" || listNode->name == "VarDef" || listNode->name == "InitVar") {
        if (listNode->name == "VarDefList") {
            for (auto* def : listNode->children) handleVarDef(def);
        } else {
            handleVarDef(listNode);
        }
        return;
    }

    for (auto* defNode : listNode->children) handleVarDef(defNode);
}

void Checker::checkFuncDef(ASTNode* node) {
    if (!node) return;
    auto* typeNode = child(node, 0);
    auto* nameNode = child(node, 1);
    auto* paramsNode = child(node, 2);
    auto* blockNode = child(node, 3);
    TYPE returnType = parseBaseType(typeNode);
    if (!nameNode) return;

    auto existing = lookupFunction(nameNode->value);
    if (existing) {
        if (existing->defined) {
            report("Redefined Function \"" + nameNode->value + "\"", nameNode);
            return;
        }
        existing->defined = true;
        existing->returnType = returnType;
    }

    FunctionInfo info;
    info.returnType = returnType;
    info.defined = true;

    vector<pair<string, TypeInfo>> params;
    if (paramsNode && paramsNode->name == "Params") {
        for (auto* param : paramsNode->children) {
            if (!param || param->name != "Param") continue;
            auto* pType = child(param, 0);
            auto* pName = child(param, 1);
            auto* pDims = child(param, 2);
            if (!pName) continue;
            TYPE pBase = parseBaseType(pType);
            int dim = countArrayDims(pDims);
            if (pDims && dim == 0) dim = 1;
            TypeInfo pinfo = buildType(pBase, dim);
            params.emplace_back(pName->value, pinfo);
            info.params.push_back(pinfo);
        }
    }

    functions_[nameNode->value] = info;

    pushScope();
    for (const auto& param : params) {
        if (!declareSymbol(param.first, Symbol{param.second, false})) report("Redefined Variable \"" + param.first + "\"", nameNode);
    }

    auto savedReturn = currentReturnType_;
    currentReturnType_ = returnType;
    checkBlock(blockNode, false);
    currentReturnType_ = savedReturn;
    popScope();
}

void Checker::checkBlock(ASTNode* node, bool createScope) {
    if (!node) return;
    if (createScope) pushScope();
    for (auto* item : node->children) {
        if (!item) continue;
        if (item->name == "BlockItems") {
            for (auto* nested : item->children) checkBlockItem(nested);
        } else {
            checkBlockItem(item);
        }
    }
    if (createScope) popScope();
}

void Checker::checkBlockItems(ASTNode* node) {
    if (!node) return;
    for (auto* item : node->children) {
        if (!item) continue;
        checkBlockItem(item);
    }
}

void Checker::checkBlockItem(ASTNode* node) {
    if (!node) return;
    if (node->name == "VarDecl") checkDecl(node);
    else checkStmt(node);
}

TypeInfo Checker::evalNumber(ASTNode* node) const {
    return isFloatNumber(node) ? makeType(FLOAT_TYPE) : makeType(INT_TYPE);
}

Checker::ExprResult Checker::evalLVal(ASTNode* node, bool /*asLValue*/) {
    ExprResult result;
    if (!node || node->name != "Name") return result;

    auto* sym = lookupSymbol(node->value);
    if (!sym) {
        report("Use Undefined Variable \"" + node->value + "\"", node);
        result.type = makeType(INT_TYPE);
        return result;
    }

    result.type = sym->type;
    result.kind = ExprKind::LValue;

    if (!node->children.empty()) {
        if (!sym->type.isArray) report("Visit non-array variable in the form of subscript variables \"" + node->value + "\"", node);
        for (auto* idx : node->children) {
            auto idxRes = evalExpr(idx);
            if (!isIntLike(idxRes.type)) report("Array index not int", idx);
        }
        if (static_cast<int>(node->children.size()) > sym->type.arrayDim) {
            result.type.isArray = false;
            result.type.arrayDim = 0;
        } else if (sym->type.arrayDim > 0) {
            result.type.arrayDim = sym->type.arrayDim - static_cast<int>(node->children.size());
            result.type.isArray = result.type.arrayDim > 0;
        }
    }

    return result;
}

Checker::ExprResult Checker::evalCall(ASTNode* node) {
    ExprResult result;
    if (!node || node->name != "Call") return result;

    auto* fn = lookupFunction(node->value);
    if (!fn) {
        report("Use Undefined Function \"" + node->value + "\"", node);
        result.type = makeType(INT_TYPE);
        return result;
    }

    vector<TypeInfo> args;
    for (auto* arg : node->children) {
        auto argRes = evalExpr(arg);
        args.push_back(argRes.type);
    }

    if (args.size() != fn->params.size()) {
        report("Can not Match Function Parameters \"" + node->value + "\"", node);
    } else {
        for (size_t i = 0; i < args.size(); ++i) {
            if (!sameTypeExact(args[i], fn->params[i])) {
                report("Can not Match Function Parameters \"" + node->value + "\"", node);
                break;
            }
        }
    }

    result.type = makeType(fn->returnType);
    result.kind = ExprKind::Call;
    return result;
}

Checker::ExprResult Checker::evalExpr(ASTNode* node) {
    ExprResult result;
    if (!node) return result;

    if (node->name == "Int" || node->name == "Float") {
        result.type = evalNumber(node);
        return result;
    }

    if (node->name == "Name") {
        return evalLVal(node, false);
    }

    if (node->name == "Call") return evalCall(node);

    if (node->name == "Assign") {
        auto lhs = evalLVal(child(node, 0), true);
        auto rhs = evalExpr(child(node, 1));
        if (!sameTypeExact(lhs.type, rhs.type) && !(isIntType(lhs.type) && rhs.type.baseType == INT_TYPE && !rhs.type.isArray)) {
            report("Func return type not match", node);
        }
        result.type = lhs.type;
        return result;
    }

    if (node->name == "+" || node->name == "-" || node->name == "*" || node->name == "/" || node->name == "%") {
        auto lhs = evalExpr(child(node, 0));
        auto rhs = evalExpr(child(node, 1));
        if (!isNumericType(lhs.type) || !isNumericType(rhs.type)) report("Func return type not match", node);
        result.type = (lhs.type.baseType == FLOAT_TYPE || rhs.type.baseType == FLOAT_TYPE) ? makeType(FLOAT_TYPE) : makeType(INT_TYPE);
        return result;
    }

    if (node->name == "==" || node->name == "!=" || node->name == "<" || node->name == "<=" || node->name == ">" || node->name == ">=") {
        auto lhs = evalExpr(child(node, 0));
        auto rhs = evalExpr(child(node, 1));
        if (lhs.type.isArray || rhs.type.isArray) report("Func return type not match", node);
        result.type = makeType(INT_TYPE);
        return result;
    }

    if (node->name == "&&" || node->name == "||") {
        evalExpr(child(node, 0));
        evalExpr(child(node, 1));
        result.type = makeType(INT_TYPE);
        return result;
    }

    if (node->name == "neg" || node->name == "!" || node->name == "~") {
        auto v = evalExpr(child(node, 0));
        result.type = v.type;
        return result;
    }

    if (node->name == "Block") {
        checkBlock(node);
        result.type = makeType(VOID_TYPE);
        return result;
    }

    return result;
}

void Checker::checkStmt(ASTNode* node) {
    if (!node) return;

    if (node->name == "EmptyStmt") return;

    if (node->name == "ExprStmt") {
        evalExpr(child(node, 0));
        return;
    }

    if (node->name == "Return") {
        auto expr = child(node, 0);
        if (!expr) {
            if (currentReturnType_ != VOID_TYPE) report("Func return type not match", node);
            return;
        }
        auto res = evalExpr(expr);
        if (currentReturnType_ == VOID_TYPE || res.type.isArray || res.type.baseType != currentReturnType_) {
            report("Func return type not match", node);
        }
        return;
    }

    if (node->name == "If") {
        evalExpr(child(node, 0));
        checkStmt(child(node, 1));
        return;
    }

    if (node->name == "IfElse") {
        evalExpr(child(node, 0));
        checkStmt(child(node, 1));
        checkStmt(child(node, 2));
        return;
    }

    if (node->name == "While") {
        evalExpr(child(node, 0));
        ++loopDepth_;
        checkStmt(child(node, 1));
        --loopDepth_;
        return;
    }

    if (node->name == "Break") {
        if (loopDepth_ == 0) report("Break not in loop", node);
        return;
    }

    if (node->name == "Continue") {
        if (loopDepth_ == 0) report("Continue not in loop", node);
        return;
    }

    if (node->name == "Block") {
        checkBlock(node);
        return;
    }

    evalExpr(node);
}
