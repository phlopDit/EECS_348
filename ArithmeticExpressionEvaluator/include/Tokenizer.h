#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <cstddef>
#include <string>
#include "Token.h"
#include "ExpressionError.h"

class Tokenizer {
  private:
    std::string input_;
    std::size_t position_;

    void skipWhiteSpace();
    Token readNum();
    char peek() const;
    char peekNext() const;
    bool isAtEnd() const;
    
  public:
    explicit Tokenizer(const std::string& input);
    Token getNextToken();
};

#endif