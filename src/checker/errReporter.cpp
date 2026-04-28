#include "../../include/checker/errReporter.hpp"

#include <iostream>

void ErrReporter::report(int line, const std::string& message) {
    errors_.push_back({line, message});
}

bool ErrReporter::hasError() const {
    return !errors_.empty();
}

const std::vector<SemanticError>& ErrReporter::errors() const {
    return errors_;
}

void ErrReporter::print() const {
    for (const auto& error : errors_) {
        if (error.line > 0) {
            std::cout << "Semantic error - line " << error.line << " : " << error.message << '\n';
        } else {
            std::cout << "Semantic error : " << error.message << '\n';
        }
    }
}
