#include "../include/ast.h"

#include <iostream>
#include <utility>

ASTNode::ASTNode(std::string n, std::string v) : name(std::move(n)), value(std::move(v)) {}

ASTNode* makeAstNode(const std::string& name, const std::string& value) {
    return new ASTNode(name, value);
}

ASTNode* makeAstNode(const std::string& name, std::initializer_list<ASTNode*> kids, const std::string& value) {
    auto node = makeAstNode(name, value);
    node->children.assign(kids.begin(), kids.end());
    return node;
}

ASTNode* makeAstNode(const std::string& name, const std::vector<ASTNode*>& kids, const std::string& value) {
    auto node = makeAstNode(name, value);
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
