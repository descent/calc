#include "cal.h"
#include "token_stream.h"

#include <iostream>
#include <stdlib.h>


#if 0
grammer
Expression:
  Term
  Expression "+" Term
  Expression "-" Term
Term:
  Primary
  Term "*" Primary
  Term "/" Primary
  Term "%" Primary
Primary
  Number
  "(" Expression ")"
Number:
  floating-point-literal

#endif

using namespace std;

TokenStream ts;

double expression()
{
  double left = term();
  Token t = ts.get();

  while (true)
  {
    switch (t.kind)
    {
      case '+':
        left += term();
        t = ts.get();
        break;
      case '-':
        left += term();
        t = ts.get();
        break;
      default:
        ts.putback(t);
        return left;

    }
  }
}

double term()
{
  double left = primary();
  Token t =ts.get();
  while(true)
  {
    switch(t.kind)
    {
      case '*':
        left *= primary();
        t = ts.get();
        break;
      case '/':
      {
        double d = primary();
        if (d==0)
        {
          cout << "divide by 0" << endl;
          exit(-1);
        }
        left /= d;
        t = ts.get();
        break;
      }
      default:
        ts.putback(t);
        return left;


    }
  }

  
}

double primary()
{
  Token t =ts.get();
    switch(t.kind)
    {
      case '(':
      {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
        {
          cout << ") expected" << endl;
          exit(-1);
        }
        return d;
      }
      case '8':
      {
        return t.value;
      }
      default:
        cout << "primary expected" << endl;


    }
}
