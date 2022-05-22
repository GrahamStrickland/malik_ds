// This is the implementation of the ADT InfxToPfx.
// The interface is in the file "infxToPfx.h".

#include "infxToPfx.h"
#include <cctype>

using namespace std;

void InfxToPfx::getInfix(const string& expr)
{
    infx = expr;
}

void InfxToPfx::showInfix() const
{
    cout << "Infix Expression: " << infx << endl;
}

void InfxToPfx::showPostfix()
{
    if (infx != "") 
        convertToPostfix();
    cout << "Postfix Expression: " << pfx << endl;
}

InfxToPfx::InfxToPfx() : infx(""), pfx("")
{
    // Function body deliberately empty.
}

InfxToPfx::~InfxToPfx()
{
    while (!symStack.empty())
        symStack.pop();
}

void InfxToPfx::convertToPostfix()
{
    char sym;
    pfx = "";

    // Get next symbol from infx.
    for (int pos = 0; pos < infx.size(); pos++) {
        sym = infx.at(pos);
        if (isalnum(sym)) {  // sym is an operand, add to pfx.
            pfx += sym;
            pfx += ' ';
        }
        else {  // sym is an operator, process using stack.
            switch(sym) {
                case '(':
                    symStack.push(sym);
                    break;
                case ')':
                    while (!symStack.empty() && symStack.top() != '(') {
                        pfx += symStack.top();
                        pfx += ' ';
                        symStack.pop();
                    }
                    symStack.pop();
                    break;
                case '+': case '-': case '*': case '/':
                    while (!symStack.empty() && symStack.top() != '(') {
                        if (precedence(symStack.top(), sym)) {
                            pfx += symStack.top();
                            pfx += ' ';
                            symStack.pop();
                        } else break;
                    }
                    symStack.push(sym);
                    break;
                default:
                    break;
            }
        }
    }

    while (!symStack.empty()) {
        pfx += symStack.top();
        pfx += ' ';
        symStack.pop();
    }
}

bool InfxToPfx::precedence(char op1, char op2) const
{
    return ((op1 == '/' || op2 == '*') && 
            (op2 == '/' || op2 == '*' || op2 == '+' || op2 == '-'))
       || ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-'));
}
