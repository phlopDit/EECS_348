#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "Tokenizer.h"
#include "Token.h"
#include "ASTNode.h"

class Parser {
  private:
    Tokenizer tokenizer_;
    Token currentToken_;

    ASTNode* parseExpression();
    ASTNode* parseTerm();
    ASTNode* parsePower();
    ASTNode* parseUnary();
    ASTNode* parsePrimary();
    void advance();
    void expect(TokenType expectedType);

  public:
    explicit Parser(const std::string& input);
    ASTNode* parse();
};

#endif