#include "../../include/ast/ast.hpp"

#include <iostream>
#include <utility>

ASTNode::ASTNode(std::string n, std::string v, int l) : name(std::move(n)), value(std::move(v)), line(l) {}

ASTNode* makeAstNode(const std::string& name, const std::string& value, int line) {
    return new ASTNode(name, value, line);
}

ASTNode* makeAstNode(const std::string& name, std::initializer_list<ASTNode*> kids, const std::string& value, int line) {
    auto node = makeAstNode(name, value, line);
    node->children.assign(kids.begin(), kids.end());
    return node;
}

ASTNode* makeAstNode(const std::string& name, const std::vector<ASTNode*>& kids, const std::string& value, int line) {
    auto node = makeAstNode(name, value, line);
    node->children = kids;
    return node;
}

void printAst(ASTNode* node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; ++i) std::cout << "  ";
    std::cout << node->name;
    if (!node->value.empty()) std::cout << ": " << node->value;
    std::cout << '\n';
    for (const auto& child : node->children) printAst(child, depth + 1);
}
