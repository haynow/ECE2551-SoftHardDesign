//
//  Matrix.cpp
//  Matrix
//

#include <vector>
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <limits> 
#include "Matrix.hpp"
#include "MatrixException.hpp"

using namespace std;

// Throw exception for invalid dimensions.
double HelpingFunctions::dotProduct(const std::vector<double> &x, const std::vector<double> &y){

}

// Throw exception for not being a square matrix.
double Matrix::getDeterminant() {

}

Matrix Matrix::getMinor(unsigned int row, unsigned int column) {

}

Matrix::Matrix(){
    rowSize = 0;
    colSize = 0;
}

// Throw exception if dimensions dont match for all columns
Matrix::Matrix(const vector<vector<double>>& data){

}

// Throw exception if dimensions dont match
void Matrix::add(const Matrix& other){

}

// Throw exception if dimensions dont match
void Matrix::subtract(const Matrix& other){

}

void Matrix::multiply(double scalar){

}

// Throw exception if dimensions dont match
void Matrix::multiply(const Matrix &other){

}

// Throw DivideByZeroError exception if attempt a division by zero
void Matrix::divide(double scalar){

}

bool Matrix::hasSameDimensionAs(const Matrix &other){
    return (other.getRowSize() != rowSize || other.getColSize() != colSize) ? false : true;
}

void Matrix::show(void) const {

}

void Matrix::zero(void) {

}

double Matrix::getAt(unsigned int x, unsigned int y) const {

}

int Matrix::getRowSize() const {
    
}

int Matrix::getColSize() const {
    
}

bool Matrix::isSquare() const {
    
}

void Matrix::transpose(void){

}

Matrix& Matrix::operator+(const Matrix& rhs) {
    
}

Matrix& Matrix::operator-(const Matrix& rhs){
    
}

Matrix& Matrix::operator*(double rhs) {    
    
}

Matrix& Matrix::operator*(const Matrix& rhs) {
    
}

Matrix& Matrix::operator/(double rhs) {
     
}

 
