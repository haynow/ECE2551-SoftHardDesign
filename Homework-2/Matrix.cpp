//
//  Matrix.cpp
//  Matrix
//
//

#include "Matrix.hpp"
#include <vector>
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

Matrix::Status Matrix::add(const Matrix &other)
{
    if (getRowSize() != other.getRowSize() || getColSize() != other.getColSize())
    {
        return DimensionError;
    }

    for (int i = 0; i <= getRowSize(); i++)
    {
        for (int j = 0; j <= getColSize(); j++)
        {
            matrix[i][j] = getAt(i, j) + other.getAt(i, j);
        }
    }
    return NoError;
};

Matrix::Status Matrix::subtract(const Matrix &other)
{
    if (getRowSize() != other.getRowSize() || getColSize() != other.getColSize())
    {
        return DimensionError;
    }

    for (int i = 0; i <= getRowSize(); i++)
    {
        for (int j = 0; j <= getColSize(); j++)
        {
            matrix[i][j] = getAt(i, j) - other.getAt(i, j);
        }
    }
    return NoError;
};

Matrix::Status Matrix::multiply(const Matrix &other)
{
    if (getColSize() != other.getRowSize() || getRowSize() != other.getColSize())
    {
        return DimensionError;
    }

    for (int i = 0; i <= getRowSize(); i++)
    {
        for (int j = 0; j <= getColSize(); j++)
        {
            matrix[i][j] = getAt(i, j) * other.getAt(j, i);
        }
    }
    return NoError;
};

Matrix::Status Matrix::divide(double scalar)
{
    for (int i = 0; i <= getRowSize(); i++)
    {
        for (int j = 0; j <= getColSize(); j++)
        {
            matrix[i][j] = getAt(i, j) / scalar;
        }
    }
    return NoError;
};

void Matrix::transpose()
{
    Matrix other(matrix);
    for (int i = 0; i <= getColSize(); i++)
    {
        for (int j = 0; j <= getRowSize(); j++)
        {
            other.matrix[i][j] = matrix[getColSize() - i][getRowSize() - j];
        }
    }
    matrix = other.matrix;
};

void Matrix::zero()
{

    for (int i = 0; i <= getRowSize(); i++)
    {
        for (int j = 0; j <= getColSize(); j++)
        {
            matrix[i][j] = 0;
        }
    }
};

void Matrix::show() const
{
    for (int i = 0; i <= getRowSize(); i++)
    {
        for (int j = 0; j <= getColSize(); j++)
        {
            printf("%d ", matrix[i][j]);
        }
        cout << "\n";
    }
};

double Matrix::getDeterminant(){};

double Matrix::getAt(int row, int column) const
{
    return matrix[row][column];
};

int Matrix::getRowSize() const
{
    return rowSize;
};

int Matrix::getColSize() const
{
    return colSize;
};

bool Matrix::isSquare() const
{
    return (getRowSize() == getColSize());
};

bool Matrix::hasSameDimensionAs(const Matrix &other)
{
    return (getRowSize() != other.getRowSize() || getColSize() != other.getColSize());
};

Matrix getMinor(int row, int column);