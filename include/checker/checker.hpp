#pragma once

#include "../ast.hpp"
#include "errReporter.hpp"

#include <string>
#include <unordered_map>
#include <vector>

struct TypeInfo {
    TYPE baseType = VOID_TYPE;
    bool isArray = false;
    int arrayDim = 0;
};

struct FunctionInfo {
    TYPE returnType = VOID_TYPE;
    std::vector<TypeInfo> params;
    bool defined = false;
};

class Checker {
public:
    explicit Checker(ErrReporter& reporter);

    void check(ASTNode* root);

private:
    struct Symbol {
        TypeInfo type;
        bool isConst = false;
    };

    enum class ExprKind { Value, LValue, Call, Bool };

    struct ExprResult {
        TypeInfo type;
        ExprKind kind = ExprKind::Value;
        bool isConstValue = false;
    };

    ErrReporter& reporter_;
    std::vector<std::unordered_map<std::string, Symbol>> scopes_;
    std::unordered_map<std::string, FunctionInfo> functions_;
    TYPE currentReturnType_ = VOID_TYPE;
    int loopDepth_ = 0;

    void pushScope();
    void popScope();
    bool declareSymbol(const std::string& name, const Symbol& symbol);
    const Symbol* lookupSymbol(const std::string& name) const;
    FunctionInfo* lookupFunction(const std::string& name);
    const FunctionInfo* lookupFunction(const std::string& name) const;
    void report(const std::string& message, ASTNode* node = nullptr) const;
    static int nodeLine(ASTNode* node);

    void checkCompUnit(ASTNode* node);
    void checkDecl(ASTNode* node);
    void checkFuncDef(ASTNode* node);
    void checkBlock(ASTNode* node, bool createScope = true);
    void checkBlockItems(ASTNode* node);
    void checkBlockItem(ASTNode* node);
    void checkStmt(ASTNode* node);
    void checkExpr(ASTNode* node);
    ExprResult evalExpr(ASTNode* node);
    ExprResult evalLVal(ASTNode* node, bool asLValue = false);
    ExprResult evalCall(ASTNode* node);
    TypeInfo evalNumber(ASTNode* node) const;

    static TypeInfo makeType(TYPE baseType, bool isArray = false, int dim = 0);
    static std::string typeName(const TypeInfo& type);
    static bool sameType(const TypeInfo& a, const TypeInfo& b);
    static bool isIntLike(const TypeInfo& type);
    static bool isNumeric(const TypeInfo& type);
    static bool isVoid(const TypeInfo& type);
    static bool isIntNumber(ASTNode* node);
    static bool isFloatNumber(ASTNode* node);
    static ASTNode* child(ASTNode* node, size_t index);
};
