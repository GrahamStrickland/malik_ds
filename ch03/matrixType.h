//**************************************************
// Author: Graham Strickland
//
// This is the interface for the ADT matrixType
//  which implements a 2-dimensional matrix of value
//  of type int, with associated operator functions.
//**************************************************

#ifndef MATRIX_TYPE_H
#define MATRIX_TYPE_H

#include <iostream>
#include <fstream>

using namespace std;

class matrixType
{
public:
    friend ostream& operator<<(ostream& outs, const
            matrixType& outpMat);
    // Overloaded stream insertion operator.
    // Precondition: outpMat is a matrix with entries
    //  initialized.
    // Postcondition: All entries of outpMat output to
    //  console.

    int operator()(int rowRef, int colRef) const; 
    // Overloaded function call operator for double-
    //  subscripted reference.
    // Precondition: rowRef and colRef are valid int
    //  references for the calling matrix.
    // Postcondition: Returned the value stored at
    //  matrix[rowRef][colRed].

    int& operator()(int rowRef, int colRef);
    // Overloaded function call operator for double-
    //  subscripted reference.
    // Precondition: rowRef and colRef are valid int
    //  references for the calling matrix.
    // Postcondition: Returned a reference to the
    //  value stored at matrix[rowRef][colRef].

    const matrixType& operator=(const matrixType& 
                                    rightMatrix);
    // Overloaded assignment operator.
    
    matrixType operator+(const matrixType&
                            rightMatrix);
    // Overloaded binary addition operator.
    // Precondition: Calling object and rightMatrix
    //  have same dimensions.
    // Postcondition: Returned new matrixType object
    //  with entries equal to the sum of corresponding 
    //  entries in calling object and rightMatrix.

    matrixType operator-(const matrixType&
                            rightMatrix);
    // Overloaded binary subtraction operator.
    // Precondition: Calling object and rightMatrix
    //  have same dimensions.
    // Postcondition: Returned new matrixType object
    //  with entries equal to the difference between
    //  corresponding entries in calling object and
    //  rightMatrix.

    matrixType operator*(const matrixType&
                            rightMatrix);
    // Overloaded binary multiplication operator.
    // Precondition: callingObject.cols == rightMatrix.rows.
    // Postcondition: Returned new matrixType object
    //  with entries equal to c_ik = a_i1*b_1k + a_i2*b_2k
    //  + ... + a_in*b_nk.

    int getRows() const;
    // Function to return number of rows.
    // Postcondition: Returned rows.

    int getCols() const;
    // Function to return number of columns.
    // Postcondition: Returned cols.

    matrixType(int numRows = 1, int numCols = 1);
    // Constructor with parameters for number of rows
    //  and number of columns.

    matrixType(const matrixType& rightMatrix);
    // Copy constructor.

    ~matrixType();
    // Destructor.
private:
    int rows;
    int cols;
    int **matrix;
};
#endif // MATRIX_TYPE_H
