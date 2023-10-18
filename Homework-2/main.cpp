#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <vector>
#include <math.h>

TEST_CASE("Testing Matrix(), getRowSize(), and getColSize()"){
    Matrix sample;
    INFO("Rows and Columns must be zero!")
    REQUIRE(sample.getRowSize() == 0);
    REQUIRE(sample.getColSize() == 0);
}

TEST_CASE("Testing Matrix(data)"){
    enum { RowOne, RowTwo };
    
    std::vector<std::vector<double>> data;
    data.resize(2);
    
    data[RowOne].push_back(1);
    data[RowOne].push_back(2);
    data[RowTwo].push_back(1);
    data[RowTwo].push_back(2);
    
    Matrix sample = Matrix(data);
    
    INFO("Rows and Columns must be two!")
    REQUIRE(sample.getRowSize() == 2);
    REQUIRE(sample.getColSize() == 2);
}

TEST_CASE("Testing isSquare()"){
    enum { RowOne, RowTwo };
    
    std::vector<std::vector<double>> data;
    data.resize(2);
    
    data[RowOne].push_back(1);
    data[RowOne].push_back(2);
    data[RowTwo].push_back(1);
    data[RowTwo].push_back(2);
    
    Matrix sample = Matrix(data);
    REQUIRE(sample.isSquare() == true);
    
    std::vector<std::vector<double>> dataTwo;
    dataTwo.resize(2);
    
    dataTwo[RowOne].push_back(1);
    dataTwo[RowOne].push_back(2);
    dataTwo[RowOne].push_back(3);
    dataTwo[RowTwo].push_back(1);
    dataTwo[RowTwo].push_back(2);
    dataTwo[RowTwo].push_back(3);
    
    Matrix sampleTwo = Matrix(dataTwo);
    REQUIRE(sampleTwo.isSquare() == false);
}

TEST_CASE("Testing getAt()"){
    enum { RowOne, RowTwo };
    
    std::vector<std::vector<double>> data;
    data.resize(2);
    
    data[RowOne].push_back(1);
    data[RowOne].push_back(2);
    data[RowTwo].push_back(1);
    data[RowTwo].push_back(2);
    
    Matrix sample = Matrix(data);
    REQUIRE(sample.getColSize() == 2);
    REQUIRE(sample.getRowSize() == 2);
    
    for (int row = 0; row < sample.getRowSize(); row++){
        for (int col = 0; col < sample.getColSize(); col++){
            REQUIRE(sample.getAt(row, col) == data[row][col]);
        }
    }
}

TEST_CASE("Testing hasSameDimensionsAs()"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> dataOne;
    std::vector<std::vector<double>> dataTwo;
    std::vector<std::vector<double>> dataThree;
    
    dataOne.resize(2);
    dataTwo.resize(2);
    dataThree.resize(3);
    
    dataOne[RowOne].push_back(1);
    dataOne[RowOne].push_back(2);
    dataOne[RowTwo].push_back(1);
    dataOne[RowTwo].push_back(2);
    
    dataTwo[RowOne].push_back(1);
    dataTwo[RowOne].push_back(2);
    dataTwo[RowTwo].push_back(3);
    dataTwo[RowTwo].push_back(1);
    
    dataThree[RowOne].push_back(1);
    dataThree[RowOne].push_back(2);
    dataThree[RowOne].push_back(3);
    dataThree[RowTwo].push_back(4);
    dataThree[RowTwo].push_back(5);
    dataThree[RowTwo].push_back(6);
    dataThree[RowThree].push_back(7);
    dataThree[RowThree].push_back(8);
    dataThree[RowThree].push_back(9);
    
    Matrix one = Matrix(dataOne);
    Matrix two = Matrix(dataTwo);
    Matrix three = Matrix(dataThree);
    
    REQUIRE(one.getRowSize() == 2);
    REQUIRE(two.getRowSize() == 2);
    REQUIRE(three.getRowSize() == 3);
    
    REQUIRE(one.hasSameDimensionAs(two) == true);
    REQUIRE(one.hasSameDimensionAs(three) == false);
}

TEST_CASE("Testing zero()"){
    enum { RowOne, RowTwo };
    
    std::vector<std::vector<double>> dataOne;
    
    dataOne.resize(2);
    
    dataOne[RowOne].push_back(1);
    dataOne[RowOne].push_back(2);
    dataOne[RowTwo].push_back(1);
    dataOne[RowTwo].push_back(2);
    
    Matrix one = Matrix(dataOne);
    one.zero();
    
    REQUIRE(one.getRowSize() == 2);
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == 0);
        }
    }
    
}

TEST_CASE("Testing Addition: NoError"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> data;
    data.resize(3);
    
    data[RowOne].push_back(1);
    data[RowOne].push_back(2);
    data[RowOne].push_back(3);
    data[RowTwo].push_back(4);
    data[RowTwo].push_back(5);
    data[RowTwo].push_back(6);
    data[RowThree].push_back(7);
    data[RowThree].push_back(8);
    data[RowThree].push_back(9);
    
    Matrix one = Matrix(data);
    Matrix two = Matrix(data);
    
    REQUIRE(one.getRowSize() == 3);
    REQUIRE(one.getColSize() == 3);
    REQUIRE(two.getRowSize() == 3);
    REQUIRE(two.getColSize() == 3);
    
    Status returnValue = one.add(two);
    REQUIRE(returnValue == NoError);
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == data[row][col] * 2);
        }
    }
}

TEST_CASE("Testing Addition: DimensionError"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> dataOne;
    std::vector<std::vector<double>> dataTwo;
    dataOne.resize(3);
    dataTwo.resize(2);
    
    dataOne[RowOne].push_back(1);
    dataOne[RowOne].push_back(2);
    dataOne[RowOne].push_back(3);
    dataOne[RowTwo].push_back(4);
    dataOne[RowTwo].push_back(5);
    dataOne[RowTwo].push_back(6);
    dataOne[RowThree].push_back(7);
    dataOne[RowThree].push_back(8);
    dataOne[RowThree].push_back(9);
    
    dataTwo[RowOne].push_back(1);
    dataTwo[RowOne].push_back(2);
    dataTwo[RowOne].push_back(3);
    dataTwo[RowTwo].push_back(4);
    dataTwo[RowTwo].push_back(5);
    dataTwo[RowTwo].push_back(6);
    
    Matrix one = Matrix(dataOne);
    Matrix two = Matrix(dataTwo);
    
    REQUIRE(one.getRowSize() == 3);
    REQUIRE(one.getColSize() == 3);
    REQUIRE(two.getRowSize() == 2);
    REQUIRE(two.getColSize() == 3);
    
    Status returnValue = one.add(two);
    REQUIRE(returnValue == DimensionError);
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == dataOne[row][col]);
        }
    }
}

TEST_CASE("Testing Subtraction: NoError"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> data;
    data.resize(3);
    
    data[RowOne].push_back(1);
    data[RowOne].push_back(2);
    data[RowOne].push_back(3);
    data[RowTwo].push_back(4);
    data[RowTwo].push_back(5);
    data[RowTwo].push_back(6);
    data[RowThree].push_back(7);
    data[RowThree].push_back(8);
    data[RowThree].push_back(9);
    
    Matrix one = Matrix(data);
    Matrix two = Matrix(data);
    
    REQUIRE(one.getRowSize() == 3);
    REQUIRE(one.getColSize() == 3);
    REQUIRE(two.getRowSize() == 3);
    REQUIRE(two.getColSize() == 3);
    
    Status returnValue = one.subtract(two);
    REQUIRE(returnValue == NoError);
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == 0);
        }
    }
}

TEST_CASE("Testing Subtraction: DimensionError"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> dataOne;
    std::vector<std::vector<double>> dataTwo;
    dataOne.resize(3);
    dataTwo.resize(2);
    
    dataOne[RowOne].push_back(1);
    dataOne[RowOne].push_back(2);
    dataOne[RowOne].push_back(3);
    dataOne[RowTwo].push_back(4);
    dataOne[RowTwo].push_back(5);
    dataOne[RowTwo].push_back(6);
    dataOne[RowThree].push_back(7);
    dataOne[RowThree].push_back(8);
    dataOne[RowThree].push_back(9);
    
    dataTwo[RowOne].push_back(1);
    dataTwo[RowOne].push_back(2);
    dataTwo[RowOne].push_back(3);
    dataTwo[RowTwo].push_back(4);
    dataTwo[RowTwo].push_back(5);
    dataTwo[RowTwo].push_back(6);
    
    Matrix one = Matrix(dataOne);
    Matrix two = Matrix(dataTwo);
    
    REQUIRE(one.getRowSize() == 3);
    REQUIRE(one.getColSize() == 3);
    REQUIRE(two.getRowSize() == 2);
    REQUIRE(two.getColSize() == 3);
    
    Status returnValue = one.subtract(two);
    REQUIRE(returnValue == DimensionError);
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == dataOne[row][col]);
        }
    }
}

TEST_CASE("Testing Multiplication: Scalar"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> data;
    data.resize(3);
    
    data[RowOne].push_back(1);
    data[RowOne].push_back(2);
    data[RowOne].push_back(3);
    data[RowTwo].push_back(4);
    data[RowTwo].push_back(5);
    data[RowTwo].push_back(6);
    data[RowThree].push_back(7);
    data[RowThree].push_back(8);
    data[RowThree].push_back(9);
    
    Matrix one = Matrix(data);
    Matrix two = Matrix(data);
    
    REQUIRE(one.getRowSize() == 3);
    REQUIRE(one.getColSize() == 3);
    REQUIRE(two.getRowSize() == 3);
    REQUIRE(two.getColSize() == 3);
    
    one.multiply(10.0);
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == data[row][col] * 10);
        }
    }
}

TEST_CASE("Testing dotProduct()"){
    std::vector<double> dataOne;
    std::vector<double> dataTwo;
    
    dataOne.push_back(1);
    dataOne.push_back(2);
    dataOne.push_back(3);
    
    dataTwo.push_back(9);
    dataTwo.push_back(8);
    dataTwo.push_back(7);
    
    double result = HelpingFunctions::dotProduct(dataOne, dataTwo);
    
    REQUIRE(result == 46);
}

TEST_CASE("Testing Multiplication: Matrix (3x3) - NoError"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> dataOne;
    std::vector<std::vector<double>> dataTwo;
    std::vector<std::vector<double>> result;
    dataOne.resize(3);
    dataTwo.resize(3);
    result.resize(3);
    
    dataOne[RowOne].push_back(1);
    dataOne[RowOne].push_back(2);
    dataOne[RowOne].push_back(3);
    dataOne[RowTwo].push_back(4);
    dataOne[RowTwo].push_back(5);
    dataOne[RowTwo].push_back(6);
    dataOne[RowThree].push_back(7);
    dataOne[RowThree].push_back(8);
    dataOne[RowThree].push_back(9);
    
    dataTwo[RowOne].push_back(9);
    dataTwo[RowOne].push_back(8);
    dataTwo[RowOne].push_back(7);
    dataTwo[RowTwo].push_back(6);
    dataTwo[RowTwo].push_back(5);
    dataTwo[RowTwo].push_back(4);
    dataTwo[RowThree].push_back(3);
    dataTwo[RowThree].push_back(2);
    dataTwo[RowThree].push_back(1);
    
    result[RowOne].push_back(30);
    result[RowOne].push_back(24);
    result[RowOne].push_back(18);
    result[RowTwo].push_back(84);
    result[RowTwo].push_back(69);
    result[RowTwo].push_back(54);
    result[RowThree].push_back(138);
    result[RowThree].push_back(114);
    result[RowThree].push_back(90);
    
    Matrix one = Matrix(dataOne);
    Matrix two = Matrix(dataTwo);
    Matrix results = Matrix(result);
    
    REQUIRE(one.getRowSize() == 3);
    REQUIRE(two.getRowSize() == 3);
    REQUIRE(results.getRowSize() == 3);
    
    Status returnValue = one.multiply(two);
    REQUIRE(returnValue == NoError);
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == results.getAt(row, col));
        }
    }
}

TEST_CASE("Testing Multiplication: DimensionError"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> dataOne;
    std::vector<std::vector<double>> dataTwo;
    
    dataOne.resize(3);
    dataTwo.resize(1);
    
    dataOne[RowOne].push_back(1);
    dataOne[RowOne].push_back(2);
    dataOne[RowOne].push_back(3);
    dataOne[RowTwo].push_back(4);
    dataOne[RowTwo].push_back(5);
    dataOne[RowTwo].push_back(6);
    dataOne[RowThree].push_back(7);
    dataOne[RowThree].push_back(8);
    dataOne[RowThree].push_back(9);
    
    dataTwo[RowOne].push_back(9);
    dataTwo[RowOne].push_back(8);
    dataTwo[RowOne].push_back(7);
    
    Matrix one = Matrix(dataOne);
    Matrix two = Matrix(dataTwo);
    
    Status returnValue = one.multiply(two);
    REQUIRE(returnValue == DimensionError);
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == dataOne[row][col]);
        }
    }
}

TEST_CASE("Testing Multiplication: Matrix (4x4) - NoError"){
    enum { RowOne, RowTwo, RowThree, RowFour };
    
    std::vector<std::vector<double>> dataOne;
    std::vector<std::vector<double>> dataTwo;
    std::vector<std::vector<double>> result;
    
    dataOne.resize(4);
    dataTwo.resize(3);
    result.resize(4);
    
    dataOne[RowOne].push_back(1);
    dataOne[RowOne].push_back(2);
    dataOne[RowOne].push_back(3);
    dataOne[RowTwo].push_back(4);
    dataOne[RowTwo].push_back(5);
    dataOne[RowTwo].push_back(6);
    dataOne[RowThree].push_back(7);
    dataOne[RowThree].push_back(8);
    dataOne[RowThree].push_back(9);
    dataOne[RowFour].push_back(10);
    dataOne[RowFour].push_back(11);
    dataOne[RowFour].push_back(12);
    
    dataTwo[RowOne].push_back(1);
    dataTwo[RowOne].push_back(2);
    dataTwo[RowOne].push_back(3);
    dataTwo[RowOne].push_back(4);
    dataTwo[RowTwo].push_back(5);
    dataTwo[RowTwo].push_back(6);
    dataTwo[RowTwo].push_back(7);
    dataTwo[RowTwo].push_back(8);
    dataTwo[RowThree].push_back(9);
    dataTwo[RowThree].push_back(10);
    dataTwo[RowThree].push_back(11);
    dataTwo[RowThree].push_back(12);
    
    result[RowOne].push_back(38);
    result[RowOne].push_back(44);
    result[RowOne].push_back(50);
    result[RowOne].push_back(56);
    result[RowTwo].push_back(83);
    result[RowTwo].push_back(98);
    result[RowTwo].push_back(113);
    result[RowTwo].push_back(128);
    result[RowThree].push_back(128);
    result[RowThree].push_back(152);
    result[RowThree].push_back(176);
    result[RowThree].push_back(200);
    result[RowFour].push_back(173);
    result[RowFour].push_back(206);
    result[RowFour].push_back(239);
    result[RowFour].push_back(272);
    
    Matrix one = Matrix(dataOne);
    Matrix two = Matrix(dataTwo);
    Matrix results = Matrix(result);
    
    REQUIRE(one.getRowSize() == 4);
    REQUIRE(two.getRowSize() == 3);
    REQUIRE(results.getRowSize() == 4);
    
    Status returnValue = one.multiply(two);
    REQUIRE(returnValue == NoError);
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == results.getAt(row, col));
        }
    }
}

TEST_CASE("Testing Division: NoError"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> dataOne;
    std::vector<std::vector<double>> result;
    
    dataOne.resize(3);
    result.resize(3);
    
    dataOne[RowOne].push_back(3);
    dataOne[RowOne].push_back(6);
    dataOne[RowOne].push_back(9);
    dataOne[RowTwo].push_back(12);
    dataOne[RowTwo].push_back(15);
    dataOne[RowTwo].push_back(18);
    dataOne[RowThree].push_back(21);
    dataOne[RowThree].push_back(24);
    dataOne[RowThree].push_back(27);
    
    result[RowOne].push_back(1);
    result[RowOne].push_back(2);
    result[RowOne].push_back(3);
    result[RowTwo].push_back(4);
    result[RowTwo].push_back(5);
    result[RowTwo].push_back(6);
    result[RowThree].push_back(7);
    result[RowThree].push_back(8);
    result[RowThree].push_back(9);
    
    Matrix one = Matrix(dataOne);
    Matrix results = Matrix(result);
    
    REQUIRE(one.getRowSize() == 3);
    REQUIRE(results.getRowSize() == 3);
    
    Status returnValue = one.divide(3.0);
    REQUIRE(returnValue == NoError);
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == results.getAt(row, col));
        }
    }
}

TEST_CASE("Testing Division: DivideByZeroError"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> dataOne;
    dataOne.resize(3);
    
    dataOne[RowOne].push_back(3);
    dataOne[RowOne].push_back(6);
    dataOne[RowOne].push_back(9);
    dataOne[RowTwo].push_back(12);
    dataOne[RowTwo].push_back(15);
    dataOne[RowTwo].push_back(18);
    dataOne[RowThree].push_back(21);
    dataOne[RowThree].push_back(24);
    dataOne[RowThree].push_back(27);
    
    Matrix one = Matrix(dataOne);
    
    Status returnValue = one.divide(0);
    REQUIRE(returnValue == DivideByZeroError);
}

TEST_CASE("Testing transpose()"){
    enum { RowOne, RowTwo, RowThree, RowFour };
    
    std::vector<std::vector<double>> dataOne;
    std::vector<std::vector<double>> result;
    
    dataOne.resize(4);
    result.resize(2);
    
    dataOne[RowOne].push_back(5);
    dataOne[RowOne].push_back(4);
    dataOne[RowTwo].push_back(4);
    dataOne[RowTwo].push_back(0);
    dataOne[RowThree].push_back(7);
    dataOne[RowThree].push_back(10);
    dataOne[RowFour].push_back(-1);
    dataOne[RowFour].push_back(8);
    
    result[RowOne].push_back(5);
    result[RowOne].push_back(4);
    result[RowOne].push_back(7);
    result[RowOne].push_back(-1);
    result[RowTwo].push_back(4);
    result[RowTwo].push_back(0);
    result[RowTwo].push_back(10);
    result[RowTwo].push_back(8);
    
    Matrix one = Matrix(dataOne);
    Matrix results = Matrix(result);
    
    REQUIRE(one.getRowSize() == 4);
    REQUIRE(results.getRowSize() == 2);
    
    one.transpose();
    
    REQUIRE(one.hasSameDimensionAs(results));
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == results.getAt(row, col));
        }
    }
    
}

TEST_CASE("Testing transpose() - 2"){
    enum { RowOne, RowTwo, RowThree, RowFour };
    
    std::vector<std::vector<double>> dataOne;
    
    dataOne.resize(4);
    
    dataOne[RowOne].push_back(5);
    dataOne[RowOne].push_back(4);
    dataOne[RowTwo].push_back(4);
    dataOne[RowTwo].push_back(0);
    dataOne[RowThree].push_back(7);
    dataOne[RowThree].push_back(10);
    dataOne[RowFour].push_back(-1);
    dataOne[RowFour].push_back(8);
    
    Matrix one = Matrix(dataOne);
    
    one.transpose();
    one.transpose();
    
    for (int row = 0; row < one.getRowSize(); row++){
        for (int col = 0; col < one.getColSize(); col++){
            REQUIRE(one.getAt(row, col) == dataOne[row][col]);
        }
    }
    
}

TEST_CASE("Testing getMinor()"){
    enum { RowOne, RowTwo, RowThree, RowFour };
    
    std::vector<std::vector<double>> dataOne;
    std::vector<std::vector<double>> result;
    dataOne.resize(4);
    result.resize(3);
    
    dataOne[RowOne].push_back(1);
    dataOne[RowOne].push_back(0);
    dataOne[RowOne].push_back(2);
    dataOne[RowOne].push_back(-1);
    dataOne[RowTwo].push_back(0);
    dataOne[RowTwo].push_back(1);
    dataOne[RowTwo].push_back(0);
    dataOne[RowTwo].push_back(-1);
    dataOne[RowThree].push_back(0);
    dataOne[RowThree].push_back(0);
    dataOne[RowThree].push_back(-6);
    dataOne[RowThree].push_back(8);
    dataOne[RowFour].push_back(0);
    dataOne[RowFour].push_back(0);
    dataOne[RowFour].push_back(0);
    dataOne[RowFour].push_back(5);
    
    result[RowOne].push_back(1);
    result[RowOne].push_back(0);
    result[RowOne].push_back(-1);
    result[RowTwo].push_back(0);
    result[RowTwo].push_back(1);
    result[RowTwo].push_back(-1);
    result[RowThree].push_back(0);
    result[RowThree].push_back(0);
    result[RowThree].push_back(5);
    
    Matrix one = Matrix(dataOne);
    Matrix results = Matrix(result);
    Matrix minor = one.getMinor(2, 2);
    
    REQUIRE(one.getRowSize() == 4);
    REQUIRE(results.getRowSize() == 3);
    
    for (int row = 0; row < minor.getRowSize(); row++){
        for (int col = 0; col < minor.getColSize(); col++){
            REQUIRE(minor.getAt(row, col) == results.getAt(row, col));
        }
    }
}

TEST_CASE("Testing getDeterminant(): Matrix 2x2"){
    enum { RowOne, RowTwo, RowThree, RowFour };
    
    std::vector<std::vector<double>> dataOne;
    
    dataOne.resize(2);
    
    dataOne[RowOne].push_back(4);
    dataOne[RowOne].push_back(6);
    dataOne[RowTwo].push_back(3);
    dataOne[RowTwo].push_back(8);
    
    Matrix one = Matrix(dataOne);
    double determinant = one.getDeterminant();
    
    REQUIRE(determinant == 14);
}

TEST_CASE("Testing getDeterminant(): Matrix 3x3"){
    enum { RowOne, RowTwo, RowThree };
    
    std::vector<std::vector<double>> dataOne;
    
    dataOne.resize(3);
    
    dataOne[RowOne].push_back(6);
    dataOne[RowOne].push_back(1);
    dataOne[RowOne].push_back(1);
    dataOne[RowTwo].push_back(4);
    dataOne[RowTwo].push_back(-2);
    dataOne[RowTwo].push_back(5);
    dataOne[RowThree].push_back(2);
    dataOne[RowThree].push_back(8);
    dataOne[RowThree].push_back(7);
    
    Matrix one = Matrix(dataOne);
    double determinant = one.getDeterminant();
    
    REQUIRE(determinant == -306);
}

TEST_CASE("Testing getDeterminant(): Matrix 4x4"){
    enum { RowOne, RowTwo, RowThree, RowFour };
    
    std::vector<std::vector<double>> dataOne;
    
    dataOne.resize(4);
    
    dataOne[RowOne].push_back(1);
    dataOne[RowOne].push_back(0);
    dataOne[RowOne].push_back(2);
    dataOne[RowOne].push_back(-1);
    dataOne[RowTwo].push_back(0);
    dataOne[RowTwo].push_back(1);
    dataOne[RowTwo].push_back(0);
    dataOne[RowTwo].push_back(-1);
    dataOne[RowThree].push_back(0);
    dataOne[RowThree].push_back(0);
    dataOne[RowThree].push_back(-6);
    dataOne[RowThree].push_back(8);
    dataOne[RowFour].push_back(0);
    dataOne[RowFour].push_back(0);
    dataOne[RowFour].push_back(0);
    dataOne[RowFour].push_back(5);
    
    Matrix one = Matrix(dataOne);
    double determinant = one.getDeterminant();
    
    REQUIRE(determinant == -30);
}

TEST_CASE("Testing getDeterminant(): Not Square Matrix"){
    enum { RowOne, RowTwo };
    
    std::vector<std::vector<double>> dataOne;
    dataOne.resize(2);
    
    dataOne[RowOne].push_back(5);
    dataOne[RowOne].push_back(4);
    dataOne[RowOne].push_back(7);
    dataOne[RowOne].push_back(-1);
    dataOne[RowTwo].push_back(4);
    dataOne[RowTwo].push_back(0);
    dataOne[RowTwo].push_back(10);
    dataOne[RowTwo].push_back(8);
    
    Matrix one = Matrix(dataOne);
    double determinant = one.getDeterminant();
    
    REQUIRE(isnan(determinant));
}