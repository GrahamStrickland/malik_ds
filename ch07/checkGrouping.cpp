// This is a driver program to test the function checkGrouping
// which uses a stack to test for correct grouping expressions
// in an arithmetic expression.

#include <iostream>
#include <string>
#include <stack>
    
using namespace std;

bool checkGrouping(const string& arithExp);

int main()
{
    string arithExp;

    cout << "Please enter an arithmetic expression: ";
    getline(cin, arithExp);

    cout << arithExp << " is " << (checkGrouping(arithExp) ? 
            "a valid expression!" : "an invalid expression!")
         << endl;

    return 0;
}

bool checkGrouping(const string& arithExp)
{
    stack<char> groupingSymbols;
    int pos = 0;

    while (pos < arithExp.length()) {
        switch (arithExp.at(pos)) {
        case '(':
        case '{':
        case '[':
            groupingSymbols.push(arithExp.at(pos));
            break;
        case ')':
            if (groupingSymbols.top() == '(')
                groupingSymbols.pop();
            else return false;
            break;
        case '}':
            if (groupingSymbols.top() == '{')
                groupingSymbols.pop();
            else return false;
            break;
        case ']':
            if (groupingSymbols.top() == '[')
                groupingSymbols.pop();
            else return false;
            break;
        }
        pos++;
    }
    
    return groupingSymbols.empty();
}
