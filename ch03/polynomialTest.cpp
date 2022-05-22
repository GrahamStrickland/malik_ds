//****************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the class polynomialType.
//****************************************************************

#include <iostream>

#include "polynomialType.h"

using namespace std;

int main()
{
    polynomialType p(8);
    polynomialType q(4);
    polynomialType t;

    cin >> p;
    cout << endl << "Line 10: p(x): " << p << endl;

    cout << "Line 11: p(5): " << p(5) << endl << endl;

    cin >> q;
    cout << endl << "Line 13: q(x): " << q << endl
         << endl;

    t = p + q;

    cout << "Line 15: p(x) + q(x): " << t << endl;

    cout << "Line 16: p(x) - q(x): " << p - q << endl;

    t = p * q;

    cout << "Line 18: p(x) * q(x): " << t << endl;

    t = ~p;

    cout << "Line 19: p\'(x) =  " << t << endl;

    return 0;
}
