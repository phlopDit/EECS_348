#ifndef ASTNODE_H
#define ASTNODE_H

class ASTNode {
  public:
    virtual ~ASTNode() = default;
    virtual double evaluate() const = 0;
};

#endif