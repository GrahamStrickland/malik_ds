//*************************************************************
// Author: D.S. Malik
//
// This program uses a stack to evaluate postfix expressions.
//*************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>

using namespace std;

void evaluateExpression(ifstream& inpF, ofstream& outF,
                        stack<double>& exprStack,
                        char& ch, bool& isExpOk);
void evaluateOpr(ofstream& out, stack<double>& exprStack,
                 char& ch, bool& isExpOk);
void discardExp(ifstream& in, ofstream& out, char& ch);
void printResult(ofstream& outF, stack<double>& exprStack,
                 bool isExpOk);

int main()
{
    bool expressionOk;
    char ch;
    stack<double> exprStack;
    ifstream infile;
    ofstream outfile;

    infile.open("RpnData.txt");

    if (!infile)
    {
        cout << "Cannot open the input file. "
             << "Program terminates!" << endl;
        return 1;
    }

    outfile.open("RpnOutput.txt");

    outfile << fixed << showpoint;
    outfile << setprecision(2);

    infile >> ch;
    while (infile)
    {
        expressionOk = true;
        outfile << ch;
        evaluateExpression(infile, outfile, exprStack, ch,
                           expressionOk);
        printResult(outfile, exprStack, expressionOk);
        infile >> ch;   //begin processing the next expression
    }

    infile.close();
    outfile.close();

    return 0;
}//end main

void evaluateExpression(ifstream& inpF, ofstream& outF,
                        stack<double>& exprStack, 
                        char& ch, bool& isExpOk)
{
    double num;
    outF << ch;

    while (ch != '=')
    {
        switch(ch)
        {
        case '#':
            inpF >> num;
            outF << num << " ";
            exprStack.push(num);
            break;

        default:
            evaluateOpr(outF, exprStack, ch, isExpOk);
        }//end switch

        if (isExpOk) //if no error
        {
            inpF >> ch;
            outF << ch;

            if (ch != '#')
                outF << " ";
        }
        else
            discardExp(inpF, outF, ch);
    }//end while (!= '=')
}//end evalutateExpression
 
void evaluateOpr(ofstream& out, stack<double>& exprStack,
                 char& ch, bool& isExpOk)
{
    double op1, op2;

    if (exprStack.empty())
    {
        out << " (Not enough operands)";
        isExpOk = false;
    }
    else
    {
        op2 = exprStack.top();
        exprStack.pop();

        if (exprStack.empty())
        {
            out << " (Not enough operands)";
            isExpOk = false;
        }
        else
        {
            op1 = exprStack.top();
            exprStack.pop();

            switch(ch)
            {
            case '+':
                exprStack.push(op1 + op2);
                break;

            case '-':
                exprStack.push(op1 - op2);
                break;

            case '*':
                exprStack.push(op1 * op2);
                break;

            case '/':
                if (op2 != 0)
                    exprStack.push(op1 / op2);
                else
                {
                    out << " (Division by 0)";
                    isExpOk = false;
                }
                break;

            default:
                out << " (Illegal operator)";
                isExpOk = false;
            }//end switch
        }//end else
    }//end else
}//end evaluateOpr
 
void discardExp(ifstream& in, ofstream& out, char& ch)
{
    while (ch != '=')
    {
        in.get(ch);
        out << ch;
    }
}//end discardExp
 
void printResult(ofstream& outF, stack<double>& exprStack,
                 bool isExpOk)
{
    double result;

    if (isExpOk)    //if no error, print the result
    {
        if (!exprStack.empty())
        {
            result = exprStack.top();
            exprStack.pop();

            if (exprStack.empty())
                outF << result << endl;
            else
                outF << " (Error: Too many operands)" << endl;
        }//end if
        else
            outF << " (Error in the expression)" << endl;
    }
    else
        outF << " (Error in the expression)" << endl;

    outF << "_________________________________"
         << endl << endl;
}//end printResult
