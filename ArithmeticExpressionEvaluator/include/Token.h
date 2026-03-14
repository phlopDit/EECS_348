#ifndef TOKEN_H
#define TOKEN_H

enum class TokenType {
  NUM,
  L_PAREN,
  R_PAREN,
  POWER,
  MULTIPLY,
  DIVIDE,
  PLUS,
  MINUS,
  MODULO,
  END
};

class Token {
  private:
   TokenType type_;
    double value_;

  public:
    explicit Token(TokenType type);
    explicit Token(TokenType type, double value);
    TokenType getType() const;
    double getValue() const;
};

#endif