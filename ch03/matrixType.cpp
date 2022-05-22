//**************************************************
// Author: Graham Strickland
//
// This is the implementation of the ADT matrixType,
//  the interface is in the file matrixType.h
//**************************************************

#include "matrixType.h"
#include <cassert>
#include <iostream>
#include <fstream>

ostream& operator<<(ostream& outs, const matrixType& outpMat)
{
    using namespace std;

    // Output matrix with '[' and ']' to delimit rows and
    //  columns.
    outs << "\n[";
    for (int row = 0; row < outpMat.rows; row++) {
        outs << ((row != 0) ? " [" : "[");
        for (int col = 0; col < outpMat.cols; col++) {
            outs << outpMat.matrix[row][col];
            outs << ((col != outpMat.cols - 1) ? ", " : "]");
        }
        outs << ((row != outpMat.rows - 1) ? ",\n" : "]");
    }
    outs << endl;

    return outs;
}

int matrixType::operator()(int rowRef, int colRef) const
{   // Check that rowRef and colRef are valid.
    assert(rowRef >= 0 && rowRef < rows && colRef >= 0 &&
            colRef < cols);

    // Return value.
    return matrix[rowRef][colRef];
}

int& matrixType::operator()(int rowRef, int colRef)
{   // Check that rowRef and colRef are valid.
    assert(rowRef >= 0 && rowRef < rows && colRef >= 0 &&
            colRef < cols);

    // Return reference.
    return matrix[rowRef][colRef];
}

const matrixType& matrixType::operator=(const matrixType&
                                            rightMatrix)
{   // Check that dimensions match rightMatrix.
    assert(rows == rightMatrix.rows && 
            cols == rightMatrix.cols);
    
    if (this != &rightMatrix)   // Avoid self-assignment.
    {
        for (int row = 0; row < rows; row++)
            delete [] matrix[rows];
        delete [] matrix;

        matrix = new int* [rows];
        assert(matrix != NULL); // Terminate if unable to
                                // allocate memory space.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++)
                matrix[row][col] = 
                    rightMatrix.matrix[row][col];
        }
    }
    
    return *this;
}

matrixType matrixType::operator+(const matrixType&
                                    rightMatrix)
{   // Check that dimensions match.
    assert(rows == rightMatrix.rows && 
            cols == rightMatrix.cols);

    // Create new matrix to store sum.
    matrixType temp(rows, cols);

    // Add entries element-wise.
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            temp.matrix[row][col] = matrix[row][col] +
                rightMatrix.matrix[row][col];

    return temp;
}

matrixType matrixType::operator-(const matrixType&
                                    rightMatrix)
{   // Check that dimensions match.
    assert(rows == rightMatrix.rows &&
            cols == rightMatrix.cols);

    // Create new matrix to store difference.
    matrixType temp(rows, cols);

    // Subtract entries element-wise.
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            temp.matrix[row][col] = matrix[row][col] -
                rightMatrix.matrix[row][col];

    return temp;
}

int matrixType::getRows() const
{
    return rows;
}

int matrixType::getCols() const
{
    return cols;
}

matrixType matrixType::operator*(const matrixType&
                                    rightMatrix)
{   // Check that inner dimensions match.
    assert(cols == rightMatrix.rows);

    // Create new matrix to store result of 
    //  matrix multiplication.
    matrixType temp(rows, rightMatrix.cols);

    // Matrix multiplication algorithm.
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < rightMatrix.cols; col++)
            for (int entry = 0; entry < cols; entry++)
                temp.matrix[row][col] += matrix[row][entry] *
                    rightMatrix.matrix[entry][col];

    return temp;
}

matrixType::matrixType(int numRows, int numCols)
{   // Assign rows and columns
    rows = numRows;
    cols = numCols;
    
    // Create new array of pointers and assign each
    //  to int pointer.
    matrix = new int* [rows];

    for (int row = 0; row < rows; row++) {
        matrix[row] = new int[cols];
        for (int col = 0; col < cols; col++)
            matrix[row][col] = 0;   // Assign each entry to 0.
    }
}

matrixType::matrixType(const matrixType& rightMatrix)
{   // Assign rows and columns from rightMatrix.
    rows = rightMatrix.rows;
    cols = rightMatrix.cols;

    // Create new array of pointers and assign each
    //  to int pointer.
    matrix = new int* [rows];
    assert(matrix != NULL); // Terminate if unable to allocate
                            // memory space.
    for (int row = 0; row < rows; row++) {
        matrix[row] = new int[cols];
        for (int col = 0; col < cols; col++) 
            matrix[row][col] = rightMatrix.matrix[row][col];
    }   // Assign each entry from rightMatrix.
}

matrixType::~matrixType()
{   // Deallocate memory for each row, then rows.
    for (int row = 0; row < rows; row++)
        delete [] matrix[row];
    delete [] matrix;
}
