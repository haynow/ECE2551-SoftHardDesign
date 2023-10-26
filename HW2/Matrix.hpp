//
//  Matrix.hpp
//  Matrix-Student
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <string>

using namespace std; 

class Matrix {
    
public:
    enum Status { NoError, DivideByZeroError, DimensionError };

    Matrix() {
    }

    Matrix(const vector<vector<double>>& data) {
        rowSize = data.size();
        colSize = data[0].size();
        matrix = data;
    }
    
    Matrix::Status add(const Matrix& other) //Fixed
    {
        if (getRowSize() != other.getRowSize() || getColSize() != other.getColSize())
        {
            return DimensionError;
        }

        for (int i = 0; i < getRowSize(); i++)
        {
            for (int j = 0; j < getColSize(); j++)
            {
                matrix[i][j] = getAt(i, j) + other.getAt(i, j);
            }
        }
        return NoError;
    };
    
    Matrix::Status subtract(const Matrix& other) //Fixed
    {
        if (getRowSize() != other.getRowSize() || getColSize() != other.getColSize())
        {
            return DimensionError;
        }

        for (int i = 0; i < getRowSize(); i++)
        {
            for (int j = 0; j < getColSize(); j++)
            {
                matrix[i][j] = getAt(i, j) - other.getAt(i, j);
            }
        }
        return NoError;
    };
    
    Status multiply(const Matrix& other) {

        if (this->getColSize() != other.getRowSize()) {
            return DimensionError;
        }

        int resultRowSize = this->getRowSize();
        int resultColSize = other.getColSize();
        int commonSize = this->getColSize(); // same as resultcolsize but its easier to read

        vector<vector<double>> result(resultRowSize, vector<double>(resultColSize, 0));

        for (int row = 0; row < resultRowSize; row++) {
            for (int col = 0; col < resultColSize; col++) {
                double sum = 0;
                for (int k = 0; k < commonSize; k++) {
                    sum += this->matrix[row][k] * other.matrix[k][col];
                }
                result[row][col] = sum;
            }
        }

        this->matrix = result;
        this->colSize = resultColSize;

        return NoError;
    }
    
    Status divide(double scalar) {

        if (scalar == 0) {
            return DivideByZeroError;
        }

        for (int row = 0; row < getRowSize(); row++) {
            for (int col = 0; col < getColSize(); col++) {
                matrix[row][col] /= scalar;
            }
        }
        return NoError;
    }

    void multiply(double scalar) {
        //cout << "Multiply method called\n";

        for (int row = 0; row < getRowSize(); row++) {
            for (int col = 0; col < getColSize(); col++) {
                matrix[row][col] *= scalar;
            }
        }
    }
    
    void transpose() {
        int newRows = this->getColSize();
        int newCols = this->getRowSize();
        vector<vector<double>> transposedMatrix(newRows, vector<double>(newCols));

        for (int row = 0; row < newRows; row++) {
            for (int col = 0; col < newCols; col++) {
                transposedMatrix[row][col] = this->matrix[col][row];
            }
        }

        this->matrix = transposedMatrix;
        this->rowSize = newRows;
        this->colSize = newCols;
    }

    void zero()  //Fixed
    {

        for (int i = 0; i < getRowSize(); i++)
        {
            for (int j = 0; j < getColSize(); j++)
            {
                matrix[i][j] = 0;
            }
        }
    };

    void show() const //Fixed
    {
        for (int i = 0; i < getRowSize(); i++)
        {
            for (int j = 0; j < getColSize(); j++)
            {
                printf("%f ", matrix[i][j]);
            }
            cout << "\n";
        }
    }
    
    double getDeterminant() {

        int rowSize = this->getRowSize();
        int colSize = this->getColSize();

        // Is it square?
        if (!this->isSquare()) {
            return nan("");  
        }

        // Edge case for 1 by 1
        if (rowSize == 1) {
            return this->matrix[0][0];
        }

        // General eq for 2 by 2
        if (rowSize == 2) {
            return this->matrix[0][0] * this->matrix[1][1] - this->matrix[0][1] * this->matrix[1][0];
        }

        double determinant = 0;

        // Recursive part that expands on 
        for (int col = 0; col < colSize; col++) {
            Matrix minorMatrix = this->getMinor(0, col);
            double minorDet = minorMatrix.getDeterminant();  // recursively compute the minor's determinant
            determinant += (col % 2 == 0 ? 1 : -1) * this->matrix[0][col] * minorDet;  // alternating signs logic (based on coordinates)
        }

        return determinant;
    }
    
    double getAt(int row, int column) const //Fixed
    {
        return matrix[row][column];
    };
    
    int getRowSize() const //Fixed
    {
        return rowSize;
    };
    
    int getColSize() const //Fixed
    {
        return colSize;
    };
    
    bool isSquare() const //Fixed
    {
        return (getRowSize() == getColSize());
    };
    
    bool hasSameDimensionAs(const Matrix& other) {

        bool result; 
        result = (other.colSize == this->colSize && other.rowSize == this->rowSize) ? true : false;
        return result; 
    }
    
    Matrix getMinor(int row, int column) {

        int newRows = this->getRowSize() - 1;
        int newCols = this->getColSize() - 1;

        vector<vector<double>> minorMatrix(newRows, vector<double>(newCols));

        int minorRow = 0;
        for (int i = 0; i < this->getRowSize(); i++) {
            if (i == row) continue; 

            int minorCol = 0;
            for (int j = 0; j < this->getColSize(); j++) {
                if (j == column) continue; 

                minorMatrix[minorRow][minorCol] = this->matrix[i][j];
                minorCol++;
            }
            minorRow++;
        }

        return Matrix(minorMatrix);
    }
    
private:
    
    int rowSize;
    
    int colSize;
    
    vector<vector<double>> matrix;

};

class HelpingFunctions {
public:
    static double dotProduct(const vector<double>& x, const vector<double>& y) {
        double dotProd = 0;
        if (x.size() == y.size()) {
            for (int i = 0; i < x.size(); i++) {
                dotProd += (x[i] * y[i]);
            }
            return dotProd;
        }
        else {
            cout << "ERROR: The vectors are two different sizes";
        }
    }
};

#endif /* Matrix_hpp */
