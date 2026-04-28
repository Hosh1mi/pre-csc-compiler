#pragma once

#include <cstring>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct ASTNode {
    string name;
    string value;
    int line = 0;
    vector<ASTNode*> children;

    ASTNode(string n, string v = "", int l = 0);
};

ASTNode* makeAstNode(const string& name, const string& value = "", int line = 0);
ASTNode* makeAstNode(const string& name, initializer_list<ASTNode*> kids, const string& value = "", int line = 0);
ASTNode* makeAstNode(const string& name, const vector<ASTNode*>& kids, const string& value = "", int line = 0);
void printAst(ASTNode* node, int depth = 0);

enum TYPE  { INT_TYPE, FLOAT_TYPE, VOID_TYPE };
enum STYPE { ST_EXPR, ST_RETURN, ST_SELECT, ST_ITERATION, ST_BLOCK, ST_BREAK, ST_CONTINUE, ST_EMPTY };
enum AOP   { AOP_ADD, AOP_SUB };
enum MOP   { MOP_MUL, MOP_DIV, MOP_MOD };
enum UOP   { UOP_POS, UOP_NEG, UOP_NOT, UOP_BITNOT };
enum ROP   { ROP_LT, ROP_LE, ROP_GT, ROP_GE };
enum EOP   { EOP_EQ, EOP_NE };

class BaseAST;
class CompUnitAST;
class DeclDefAST;
class DeclAST;
class DefListAST;
class DefAST;
class ArraysAST;
class InitValListAST;
class InitValAST;
class FuncDefAST;
class FuncFParamListAST;
class FuncFParamAST;
class BlockAST;
class BlockItemListAST;
class BlockItemAST;
class StmtAST;
class ReturnStmtAST;
class SelectStmtAST;
class IterationStmtAST;
class LValAST;
class PrimaryExpAST;
class NumberAST;
class UnaryExpAST;
class CallAST;
class FuncCParamListAST;
class MulExpAST;
class AddExpAST;
class RelExpAST;
class EqExpAST;
class LAndExpAST;
class LOrExpAST;
class Visitor;

class BaseAST {
public:
    BaseAST() = default;
    virtual ~BaseAST() = default;
};

class CompUnitAST : public BaseAST {
public:
    vector<unique_ptr<DeclDefAST>> declDefList;
};

class DeclDefAST : public BaseAST {
public:
    unique_ptr<DeclAST> Decl = nullptr;
    unique_ptr<FuncDefAST> funcDef = nullptr;
};

class DeclAST : public BaseAST {
public:
    TYPE bType;
    bool isConst;
    vector<unique_ptr<DefAST>> defList;
};

class DefListAST {
public:
    vector<unique_ptr<DefAST>> list;
};

class DefAST : public BaseAST {
public:
    unique_ptr<string> id;
    vector<unique_ptr<AddExpAST>> arrays;
    unique_ptr<InitValAST> initVal;
};

class ArraysAST {
public:
    vector<unique_ptr<AddExpAST>> list;
};

class InitValAST : public BaseAST {
public:
    unique_ptr<AddExpAST> exp;
    vector<unique_ptr<InitValAST>> initValList;
};

class InitValListAST {
public:
    vector<unique_ptr<InitValAST>> list;
};

class FuncDefAST : public BaseAST {
public:
    TYPE funcType;
    unique_ptr<string> id;
    vector<unique_ptr<FuncFParamAST>> funcFParamList;
    unique_ptr<BlockAST> block = nullptr;
};

class FuncFParamListAST {
public:
    vector<unique_ptr<FuncFParamAST>> list;
};

class FuncFParamAST : public BaseAST {
public:
    TYPE bType;
    unique_ptr<string> id;
    bool isArray = false;
    vector<unique_ptr<AddExpAST>> arrays;
};

class BlockAST : public BaseAST {
public:
    vector<unique_ptr<BlockItemAST>> blockItemList;
};

class BlockItemListAST {
public:
    vector<unique_ptr<BlockItemAST>> list;
};

class BlockItemAST : public BaseAST {
public:
    unique_ptr<DeclAST> decl = nullptr;
    unique_ptr<StmtAST> stmt = nullptr;
};

class StmtAST : public BaseAST {
public:
    STYPE sType;
    unique_ptr<LValAST> lVal = nullptr;
    unique_ptr<AddExpAST> exp = nullptr;
    unique_ptr<ReturnStmtAST> returnStmt = nullptr;
    unique_ptr<SelectStmtAST> selectStmt = nullptr;
    unique_ptr<IterationStmtAST> iterationStmt = nullptr;
    unique_ptr<BlockAST> block = nullptr;
};

class ReturnStmtAST : public BaseAST {
public:
    unique_ptr<AddExpAST> exp = nullptr;
};

class SelectStmtAST : public BaseAST {
public:
    unique_ptr<LOrExpAST> cond;
    unique_ptr<StmtAST> ifStmt, elseStmt;
};

class IterationStmtAST : public BaseAST {
public:
    unique_ptr<LOrExpAST> cond;
    unique_ptr<StmtAST> stmt;
};

class AddExpAST : public BaseAST {
public:
    unique_ptr<AddExpAST> addExp;
    unique_ptr<MulExpAST> mulExp;
    AOP op;
};

class MulExpAST : public BaseAST {
public:
    unique_ptr<UnaryExpAST> unaryExp;
    unique_ptr<MulExpAST> mulExp;
    MOP op;
};

class UnaryExpAST : public BaseAST {
public:
    unique_ptr<PrimaryExpAST> primaryExp;
    unique_ptr<CallAST> call;
    unique_ptr<UnaryExpAST> unaryExp;
    UOP op;
};

class PrimaryExpAST : public BaseAST {
public:
    unique_ptr<AddExpAST> exp;
    unique_ptr<LValAST> lval;
    unique_ptr<NumberAST> number;
};

class NumberAST : public BaseAST {
public:
    bool isInt;
    union {
        int intval;
        float floatval;
    };
};

class LValAST : public BaseAST {
public:
    unique_ptr<string> id;
    vector<unique_ptr<AddExpAST>> arrays;
};

class CallAST : public BaseAST {
public:
    unique_ptr<string> id;
    vector<unique_ptr<AddExpAST>> funcCParamList;
};

class FuncCParamListAST {
public:
    vector<unique_ptr<AddExpAST>> list;
};

class RelExpAST : public BaseAST {
public:
    unique_ptr<AddExpAST> addExp;
    unique_ptr<RelExpAST> relExp;
    ROP op;
};

class EqExpAST : public BaseAST {
public:
    unique_ptr<RelExpAST> relExp;
    unique_ptr<EqExpAST> eqExp;
    EOP op;
};

class LAndExpAST : public BaseAST {
public:
    unique_ptr<EqExpAST> eqExp;
    unique_ptr<LAndExpAST> lAndExp;
};

class LOrExpAST : public BaseAST {
public:
    unique_ptr<LOrExpAST> lOrExp;
    unique_ptr<LAndExpAST> lAndExp;
};

class Visitor {
public:
    virtual void visit(CompUnitAST& ast) = 0;
    virtual void visit(DeclDefAST& ast) = 0;
    virtual void visit(DeclAST& ast) = 0;
    virtual void visit(DefAST& ast) = 0;
    virtual void visit(InitValAST& ast) = 0;
    virtual void visit(FuncDefAST& ast) = 0;
    virtual void visit(FuncFParamAST& ast) = 0;
    virtual void visit(BlockAST& ast) = 0;
    virtual void visit(BlockItemAST& ast) = 0;
    virtual void visit(StmtAST& ast) = 0;
    virtual void visit(ReturnStmtAST& ast) = 0;
    virtual void visit(SelectStmtAST& ast) = 0;
    virtual void visit(IterationStmtAST& ast) = 0;
    virtual void visit(AddExpAST& ast) = 0;
    virtual void visit(MulExpAST& ast) = 0;
    virtual void visit(UnaryExpAST& ast) = 0;
    virtual void visit(PrimaryExpAST& ast) = 0;
    virtual void visit(LValAST& ast) = 0;
    virtual void visit(NumberAST& ast) = 0;
    virtual void visit(CallAST& ast) = 0;
    virtual void visit(RelExpAST& ast) = 0;
    virtual void visit(EqExpAST& ast) = 0;
    virtual void visit(LAndExpAST& ast) = 0;
    virtual void visit(LOrExpAST& ast) = 0;
};
