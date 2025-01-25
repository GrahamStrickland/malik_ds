//****************************************************
// Author: Graham Strickland
//
// Driver program to test the class complexPolynomial.
//****************************************************

#include <iostream>

#include "complexPolynomial.h"

using namespace std;

int main() {
  // Declaration of variables.
  complexPolynomial p(8);
  complexPolynomial q(4);
  complexPolynomial t;
  double *z;
  z = new double[COMP_LEN];

  // Input and output polynomials p and q.
  cin >> p;
  cout << endl
       << "Line 25: p(z): " << p << endl
       << "Please enter a value at which to evaluate p.\n"
       << "(Re): ";
  cin >> z[0];
  cout << "(Im): ";
  cin >> z[1];
  cout << "p(" << z[0];
  if (z[1] >= 0.0)
    cout << "+" << z[1] << "j): ";
  else
    cout << "-" << -z[1] << "j): ";
  z = p(z);
  cout << "(" << z[0];
  if (z[1] >= 0.0)
    cout << "+" << z[1] << "j)\n\n";
  else
    cout << "-" << -z[1] << "j)\n\n";

  cin >> q;
  cout << endl
       << "Line 37: q(z): " << q << endl
       << "Please enter a value at which to evaluate q.\n"
       << "(Re): ";
  cin >> z[0];
  cout << "(Im): ";
  cin >> z[1];
  cout << "q(" << z[0];
  if (z[1] >= 0.0)
    cout << "+" << z[1] << "j): ";
  else
    cout << "-" << -z[1] << "j): ";
  z = q(z);
  cout << "(" << z[0];
  if (z[1] >= 0.0)
    cout << "+" << z[1] << "j)\n\n";
  else
    cout << "-" << -z[1] << "j)\n\n ";

  // Calculate sum of p and q and output.
  t = p + q;

  cout << "Line 56: p(z) + q(z): " << t << endl;

  // Calculate difference between p and q and output.
  cout << "Line 59: p(z) - q(z): " << p - q << endl;

  // Calculate product of p and q and output.
  cout << "Line 62: p(z) * q(z): " << p * q << endl;

  return 0;
}
