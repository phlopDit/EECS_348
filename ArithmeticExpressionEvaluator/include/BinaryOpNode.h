#ifndef BINARYOPNODE_H
#define BINARYOPNODE_H
#include "ASTNode.h"
#include "Token.h"

class BinaryOpNode : public ASTNode{
  private:
    TokenType op_;
    ASTNode* leftChild_;
    ASTNode* rightChild_;
    
  public:
    BinaryOpNode(TokenType op, ASTNode leftChild, ASTNode rightChild);
    ~BinaryOpNode() override;
    double evaluate() const override;
};

#endif
