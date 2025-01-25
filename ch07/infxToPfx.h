#ifndef INFX_TO_PFX_H
#define INFX_TO_PFX_H

// This is the interface of the ADT InfxToPfx
// that stores an expression in infix notation
// and converts it to postfix notation. The
// implementation is in the file "infxToPfx.cpp".

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class InfxToPfx {
public:
  void getInfix(const string &expr);
  // Function to store the infix expression.
  // Postcondition: Expression stored in infx.

  void showInfix() const;
  // Function to output the infix expression.
  // Postcondition: infx printed to console.

  void showPostfix();
  // Function to output the postfix expression.
  // Postcondition: pfx printed to console.

  InfxToPfx();
  // Default constructor.

  ~InfxToPfx();
  // Destructor.
private:
  string infx;
  string pfx;
  stack<char> symStack;

  void convertToPostfix();
  // Function to convert the infix expression into
  // a postfix expression.
  // Postcondition: Postfix expression stored in pfx.

  bool precedence(char op1, char op2) const;
  // Function to determine the precedence between
  // two operators.
  // Postcondition: Returned true if the first operator
  // is of higher or equal precedence than the second,
  // otherwise returned false.
};

#endif // INFX_TO_PFX_H
