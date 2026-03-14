#ifndef UNARYOPNODE_H
#define UNARYOPNODE_H
#include "ASTNode.h"
#include "Token.h"

class UnaryOpNode : public ASTNode {
  private:
    TokenType op_;
    ASTNode* operand_;
    
  public:
  UnaryOpNode(TokenType op, ASTNode* operand);
  ~UnaryOpNode() override;
  double evaluate() const override;
};

#endif