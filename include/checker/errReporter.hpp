#pragma once

#include <string>
#include <vector>

struct SemanticError {
    int line = 0;
    std::string message;
};

class ErrReporter {
public:
    void report(int line, const std::string& message);
    bool hasError() const;
    const std::vector<SemanticError>& errors() const;
    void print() const;

private:
    std::vector<SemanticError> errors_;
};
