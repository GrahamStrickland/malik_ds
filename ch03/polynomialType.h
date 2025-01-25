//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// polynomial operations.
//***********************************************************

#include "arrayListType.h"

#include <iostream>

#include <cmath>

using namespace std;

class polynomialType : public arrayListType<double> {
  friend ostream &operator<<(ostream &, const polynomialType &);
  // Overloads the stream insertion operator
  friend istream &operator>>(istream &, polynomialType &);
  // Overloads the stream extraction operator
  friend polynomialType operator+(const polynomialType &,
                                  const polynomialType &);
  // Overloads the operator +
  friend polynomialType operator-(const polynomialType &,
                                  const polynomialType &);
  // Overloads the operator -

public:
  polynomialType operator*(const polynomialType &);
  // Overloads the operator *
  polynomialType operator~() const;
  // Overloads the operator ~ to calculate the derivative of
  // the polynomial.
  // Postcondition: The derivative of the polynomial is calculated
  //   and returned.
  double operator()(double x);
  // Overloads the operator () to evaluate the polynomial at
  // a given point
  // Postcondition: The value of the polynomial at x is
  //   calculated and returned

  polynomialType(int size = 100);
  // constructor

  int min(int x, int y) const;
  // Function to return the smaller of x and y
  int max(int x, int y) const;
  // Function to return the larger of x and y
};

polynomialType::polynomialType(int size) : arrayListType<double>(size) {
  length = size;

  for (int i = 0; i < size; i++)
    list[i] = 0;
}

polynomialType polynomialType::operator*(const polynomialType &right) {
  int size = length + right.length;

  polynomialType temp(size); // polynomial to store the product

  for (int i = 0; i < size; i++) {
    temp.list[i] = 0;
    for (int j = 0; j <= i; j++)
      if (j < length && i - j < right.length)
        temp.list[i] += list[j] * right.list[i - j];
  }

  return temp;
}

polynomialType polynomialType::operator~() const {
  if (length == 1) {
    polynomialType temp(1);
    temp.list[0] = 0;
    return temp;
  } else {
    polynomialType temp(length - 1);
    for (int i = 0; i < temp.length; i++)
      if (i == 0)
        temp.list[i] = list[i + 1];
      else
        temp.list[i] = list[i + 1] * (i + 1);
    return temp;
  }
}

double polynomialType::operator()(double x) {
  double value = 0.0;

  for (int i = 0; i < length; i++) {
    if (list[i] != 0.0)
      value = value + list[i] * pow(x, i);
  }

  return value;
}

int polynomialType::min(int x, int y) const {
  if (x <= y)
    return x;
  else
    return y;
}

int polynomialType::max(int x, int y) const {
  if (x >= y)
    return x;
  else
    return y;
}

ostream &operator<<(ostream &os, const polynomialType &p) {
  int indexFirstNonzeroCoeff = 0;

  for (int i = 0; i < p.length; i++) // determine the index of the
                                     // first nonzero coefficient
    if (p.list[i] != 0.0) {
      indexFirstNonzeroCoeff = i;
      break;
    }

  if (indexFirstNonzeroCoeff < p.length) {
    if (indexFirstNonzeroCoeff == 0)
      os << p.list[indexFirstNonzeroCoeff] << " ";
    else
      os << p.list[indexFirstNonzeroCoeff] << "x^" << indexFirstNonzeroCoeff
         << " ";

    for (int i = indexFirstNonzeroCoeff + 1; i < p.length; i++) {
      if (p.list[i] != 0.0) {
        if (p.list[i] >= 0.0)
          os << "+ " << p.list[i] << "x^" << i << " ";
        else
          os << "- " << -p.list[i] << "x^" << i << " ";
      }
    }
  } else
    os << "0";

  return os;
}

istream &operator>>(istream &is, polynomialType &p) {
  cout << "The degree of this polynomial is: " << p.length - 1 << endl;

  for (int i = 0; i < p.length; i++) {
    cout << "Enter the coefficient of x^" << i << ": ";
    is >> p.list[i];
  }

  return is;
}

polynomialType operator+(const polynomialType &left,
                         const polynomialType &right) {
  int size = max(left.length, right.length);

  polynomialType temp(size); // polynomial to store the sum

  for (int i = 0; i < min(left.length, right.length); i++)
    temp.list[i] = left.list[i] + right.list[i];

  if (size == left.length)
    for (int i = min(left.length, right.length); i < left.length; i++)
      temp.list[i] = left.list[i];
  else
    for (int i = min(left.length, right.length); i < right.length; i++)
      temp.list[i] = right.list[i];

  return temp;
}

polynomialType operator-(const polynomialType &left,
                         const polynomialType &right) {
  int size = max(left.length, right.length);

  polynomialType temp(size); // polynomial to store the difference

  for (int i = 0; i < min(left.length, right.length); i++)
    temp.list[i] = left.list[i] - right.list[i];

  if (size == left.length)
    for (int i = min(left.length, right.length); i < left.length; i++)
      temp.list[i] = left.list[i];
  else
    for (int i = min(left.length, right.length); i < right.length; i++)
      temp.list[i] = -right.list[i];

  return temp;
}
