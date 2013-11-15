#include "token_stream.h"

#include <iostream>

using namespace std;

TokenStream::TokenStream()
  :full_(false), buffer_(0)
{
}

Token TokenStream::get()
{
  if (full_)
  {
    full_  = false;
    return buffer_;
  }

  char ch;
  cin >> ch;

  switch (ch)
  {
    case ';':
    case 'q':
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
      return Token(ch);
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
      cin.putback(ch);
      double val;
      cin >> val;
      return Token('8', val);
    }
    default:
      cout << "bad token";
  }

}

void TokenStream::putback(Token t)
{
  if (full_)
  {
    cout << "buffer is full" << endl;
    return;
  }
  buffer_ = t;
  full_ = true;
}
