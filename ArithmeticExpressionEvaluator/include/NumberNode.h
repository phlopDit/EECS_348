#ifndef NUMBERNODE_H
#define NUMBERNODE_H
#include "ASTNode.h"

class NumberNode : public ASTNode {
  private:
    double value_;
    
  public:
    explicit NumberNode(double value);
    double evaluate() const override;
};

#endif