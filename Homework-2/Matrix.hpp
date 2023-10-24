//
//  Matrix.hpp
//  Matrix-Student
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <vector>

class Matrix
{

public:
    Matrix();

    enum Status
    {
        NoError,
        DivideByZeroError,
        DimensionError
    };

    Matrix(const std::vector<std::vector<double>> &data)
    {
        this->matrix = data;
        this->rowSize = data.size();
        this->colSize = data[0].size();
    }

    Status add(const Matrix &other);

    Status subtract(const Matrix &other);

    Status multiply(const Matrix &other);

    Status divide(double scalar);

    void multiply(double scalar);

    void transpose();

    void zero();

    void show() const;

    double getDeterminant();

    double getAt(int row, int column) const;

    int getRowSize() const;

    int getColSize() const;

    bool isSquare() const;

    bool hasSameDimensionAs(const Matrix &other);

    Matrix getMinor(int row, int column);

private:
    int rowSize;

    int colSize;

    std::vector<std::vector<double>> matrix;
};

class HelpingFunctions
{
public:
    static double dotProduct(const std::vector<double> &x, const std::vector<double> &y);
};

#endif /* Matrix_hpp */
