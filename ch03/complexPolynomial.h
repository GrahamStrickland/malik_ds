//********************************************************
// Author: G.H. Strickland
//
// This class specifies the members to implement the basic
// polynomial operations for a complex polynomial.
//********************************************************

#include "arrayListType.h"

#include <iostream>

#include <cmath>

const int COMP_LEN = 2;

using namespace std;

class complexPolynomial : public arrayListType<double *> {
  friend ostream &operator<<(ostream &, const complexPolynomial &);
  // Overloads the stream insertion operator
  friend istream &operator>>(istream &, complexPolynomial &);
  // Overloads the stream extraction operator
  friend complexPolynomial operator+(const complexPolynomial &,
                                     const complexPolynomial &);
  // Overloads the operator +
  friend complexPolynomial operator-(const complexPolynomial &,
                                     const complexPolynomial &);
  // Overloads the operator -
public:
  complexPolynomial operator*(const complexPolynomial &);
  // Overloads the operator *
  double *operator()(double *z);
  // Overloads the operator () to evaluate the polynomial at
  //   a given point
  // Postcondition: The value of the polynomial at z is
  //   calculated and returned

  complexPolynomial(int size = 100);
  // constructor

  int min(int x, int y) const;
  // Function to return the smaller of x and y
  int max(int x, int y) const;
  // Function to return the larger of x and y
};

ostream &operator<<(ostream &os, const complexPolynomial &p) {
  int indexFirstNonzeroCoeff = 0;

  for (int i = 0; i < p.length; i++) // determine the index of the
                                     // first nonzero coefficient
    if (p.list[i][0] != 0.0 || p.list[i][1] != 0.0) {
      indexFirstNonzeroCoeff = i;
      break;
    }

  if (indexFirstNonzeroCoeff < p.length) {
    if (indexFirstNonzeroCoeff == 0)
      os << "(" << p.list[indexFirstNonzeroCoeff][0] << "+"
         << p.list[indexFirstNonzeroCoeff][1] << "j) ";
    else
      os << "(" << p.list[indexFirstNonzeroCoeff][0] << "+"
         << p.list[indexFirstNonzeroCoeff][1] << "j)z^"
         << indexFirstNonzeroCoeff << " ";

    for (int i = indexFirstNonzeroCoeff + 1; i < p.length; i++) {
      if (p.list[i][0] != 0.0 || p.list[i][1] != 0.0) {
        if (p.list[i][0] >= 0.0)
          os << "+ (" << p.list[i][0];
        else
          os << "+ (-" << -p.list[i][0];
        if (p.list[i][1] >= 0.0)
          os << "+" << p.list[i][1] << "j)*z^" << i << " ";
        else
          os << "-" << -p.list[i][1] << "j)*z^" << i << " ";
      }
    }
  } else
    os << "0";

  return os;
}

istream &operator>>(istream &is, complexPolynomial &p) {
  cout << "The degree of this polynomial is: " << p.length - 1 << endl;

  for (int i = 0; i < p.length; i++) {
    cout << "Enter the coefficient of z^" << i << "\n(Re): ";
    is >> p.list[i][0];
    cout << "(Im): ";
    is >> p.list[i][1];
  }

  return is;
}

complexPolynomial operator+(const complexPolynomial &left,
                            const complexPolynomial &right) {
  int size = max(left.length, right.length);

  complexPolynomial temp; // Polynomial to store the sum.

  for (int i = 0; i < min(left.length, right.length); i++) {
    temp.list[i][0] = left.list[i][0] + right.list[i][0];
    temp.list[i][1] = left.list[i][1] + right.list[i][1];
  }

  if (size == left.length)
    for (int i = min(left.length, right.length); i < left.length; i++) {
      temp.list[i][0] = left.list[i][0];
      temp.list[i][1] = left.list[i][1];
    }
  else
    for (int i = min(left.length, right.length); i < right.length; i++) {
      temp.list[i][0] = right.list[i][0];
      temp.list[i][1] = right.list[i][1];
    }

  return temp;
}

complexPolynomial operator-(const complexPolynomial &left,
                            const complexPolynomial &right) {
  int size = max(left.length, right.length);

  complexPolynomial temp; // Polynomial to store the difference.

  for (int i = 0; i < min(left.length, right.length); i++) {
    temp.list[i][0] = left.list[i][0] - right.list[i][0];
    temp.list[i][1] = left.list[i][1] - right.list[i][1];
  }

  if (size == left.length)
    for (int i = min(left.length, right.length); i < left.length; i++) {
      temp.list[i][0] = left.list[i][0];
      temp.list[i][1] = left.list[i][1];
    }
  else
    for (int i = min(left.length, right.length); i < right.length; i++) {
      temp.list[i][0] = -right.list[i][0];
      temp.list[i][1] = -right.list[i][1];
    }

  return temp;
}

complexPolynomial complexPolynomial::operator*(const complexPolynomial &right) {
  int size = length + right.length;

  complexPolynomial temp(size); // Polynomial to store the product.

  for (int i = 0; i < size; i++) {
    temp.list[i][0] = 0;
    temp.list[i][1] = 0;
    for (int j = 0; j <= i; j++) {
      if (j < length && i - j < right.length) {
        temp.list[i][0] += list[j][0] * right.list[i - j][0] -
                           list[j][1] * right.list[i - j][1];
        temp.list[i][1] += list[j][0] * right.list[i - j][1] +
                           list[j][1] * right.list[i - j][0];
      }
    }
  }

  return temp;
}

double *complexPolynomial::operator()(double *z) {
  double *value, *temp;
  value = new double[COMP_LEN];

  for (int i = 0; i < length; i++) {
    temp = z;
    for (int j = 0; j < i; j++) {
      temp[0] = temp[0] * z[0] - temp[1] * z[1];
      temp[1] = temp[0] * z[1] + temp[1] * z[0];
    }
    value[0] += z[0] * list[i][0] - z[1] * list[i][1];
    value[1] += z[0] * list[i][1] + z[1] * list[i][0];
  }

  return value;
}

complexPolynomial::complexPolynomial(int size) : arrayListType<double *>(size) {
  length = size;

  for (int i = 0; i < size; i++) {
    list[i] = new double[COMP_LEN];
    list[i][0] = 0.0;
    list[i][1] = 0.0;
  }
}

int complexPolynomial::min(int x, int y) const {
  if (x <= y)
    return x;
  else
    return y;
}

int complexPolynomial::max(int x, int y) const {
  if (x >= y)
    return x;
  else
    return y;
}
