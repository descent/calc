#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

class Token
{
  public:
    Token(char ch):kind(ch), value(0)
    {
    }
    Token(char ch, double val) : kind(ch), value(val)
    {
    }
    char kind;
    double value;
  private:
};

class TokenStream
{
  public:
    TokenStream();
    Token get();
    void putback(Token t);
  private:
    bool full_;
    Token buffer_;
};

#endif
