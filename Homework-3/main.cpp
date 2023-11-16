//
//  main.cpp
//  Pointers-Students
//
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"
#include <iostream>

TEST_CASE("Testing getCharacterAddress()"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'f', 'i', 'r', 's', 't'},
        {'s', 'e', 'c', 'o', 'n'},
        {'t', 'h', 'i', 'r', 'd'},
        {'f', 'o', 'u', 'r', 't'},
        {'f', 'i', 'f', 't', 'h'}
    };
    
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            void* address = getCharacterAddress(first, i, j);
            INFO("Testing Address: " << address << " to contain: " << first[i][j]);
            REQUIRE(*(char*)address == first[i][j]);
        }
    }
}

TEST_CASE("Testing getCharacter() - One Character"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'a', 'q', 'a', 'z', 'p'},
        {'b', 'w', 's', 'x', 'o'},
        {'c', 'e', 'd', 'c', 'i'},
        {'d', 'r', 'f', 'v', 'u'},
        {'e', 't', 'g', 'b', 'y'}
    };
    
    char character = getCharacter(first, 2, 2);
    REQUIRE(character == first[2][2]);
}


TEST_CASE("Testing getCharacter() - All Characters"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'z', 'n', 'f', 'l', 't'},
        {'x', 'm', 'g', 'q', 'y'},
        {'c', 'a', 'h', 'w', 'u'},
        {'v', 's', 'j', 'e', 'i'},
        {'b', 'd', 'k', 'r', 'o'}
    };
    
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            char character = getCharacter(first, i, j);
            REQUIRE(character == first[i][j]);
        }
    }
}

TEST_CASE("Testing getCharacter() - Pointer Check"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'f', 'i', 'r', 's', 't'},
        {'s', 'e', 'c', 'o', 'n'},
        {'t', 'h', 'i', 'r', 'd'},
        {'f', 'o', 'u', 'r', 't'},
        {'f', 'i', 'f', 't', 'h'}
    };
    
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            char character = getCharacter(first, i, j);
            void* address = getCharacterAddress(first, i, j);
            REQUIRE(*(char*)address == character);
        }
    }
}

TEST_CASE("Testing getRow()"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'f', 'i', 'r', 's', 't'},
        {'s', 'e', 'c', 'o', 'n'},
        {'t', 'h', 'i', 'r', 'd'},
        {'f', 'o', 'u', 'r', 't'},
        {'f', 'i', 'f', 't', 'h'}
    };
    
    const unsigned int size = 6;
    const unsigned int rowNumber = 3;
    char row[size];
    
    getRow(first, rowNumber, row);
    
    for (int i = 0; i < size - 1; i++){
        REQUIRE(row[i] == first[rowNumber][i]);
    }
}

TEST_CASE("Testing getColumn()"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'f', 'i', 'r', 's', 't'},
        {'s', 'e', 'c', 'o', 'n'},
        {'t', 'h', 'i', 'r', 'd'},
        {'f', 'o', 'u', 'r', 't'},
        {'f', 'i', 'f', 't', 'h'}
    };
    
    const unsigned int size = 6;
    const unsigned int columnNumber = 3;
    char column[size];
    
    getColumn(first, columnNumber, column);
    
    for (int i = 0; i < size - 1; i++){
        REQUIRE(column[i] == first[i][columnNumber]);
    }
}

TEST_CASE("Testing insertionSort() - 1"){
    char test[5] = {'a', 'x', 'b', 'z', 'c'};
    char testResults[5] = {'a', 'b', 'c', 'x', 'z'};
    
    insertionSort(test, 5);
    
    for (int i = 0; i < 5; i++){
        REQUIRE(test[i] == testResults[i]);
    }
}

TEST_CASE("Testing insertionSort() - 2"){
    char test[5] = {'a', 'b', 'c', 'd', 'e'};
    char testResults[5] = {'a', 'b', 'c', 'd', 'e'};
    
    insertionSort(test, 5);
    
    for (int i = 0; i < 5; i++){
        REQUIRE(test[i] == testResults[i]);
    }
}

TEST_CASE("Testing insertionSort() - 3"){
    char test[5] = {'a', 'A', 'a', 'a', 'b'};
    char testResults[5] = {'A', 'a', 'a', 'a', 'b'};
    
    insertionSort(test, 5);
    
    for (int i = 0; i < 5; i++){
        REQUIRE(test[i] == testResults[i]);
    }
}

TEST_CASE("Testing insertionSort() - 4"){
    char test[5] = {'a', 'A', 'b', 'B', 'z'};
    char testResults[5] = {'A', 'B', 'a', 'b', 'z'};
    
    insertionSort(test, 5);
    
    for (int i = 0; i < 5; i++){
        REQUIRE(test[i] == testResults[i]);
    }
}

TEST_CASE("Testing insertionSort() - 5"){
    char test[5] = {'z', 'y', 'x', 'w', 'v'};
    char testResults[5] = {'v', 'w', 'x', 'y', 'z'};
    
    insertionSort(test, 5);
    
    for (int i = 0; i < 5; i++){
        REQUIRE(test[i] == testResults[i]);
    }
}

TEST_CASE("Testing insertionSort() - 6"){
    char test[5] = {'a', 'a', 'a', 'a', 'a'};
    char testResults[5] = {'a', 'a', 'a', 'a', 'a'};
    
    insertionSort(test, 5);
    
    for (int i = 0; i < 5; i++){
        REQUIRE(test[i] == testResults[i]);
    }
}

TEST_CASE("Testing insertionSort() - 7"){
    char test[5] = {'a', 'b', 'b', 'a', 'b'};
    char testResults[5] = {'a', 'a', 'b', 'b', 'b'};
    
    insertionSort(test, 5);
    
    for (int i = 0; i < 5; i++){
        REQUIRE(test[i] == testResults[i]);
    }
}

TEST_CASE("Testing sortRow() - 1"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'a', 'q', 'a', 'z', 'p'},
        {'b', 'a', 'b', 'a', 'c'},
        {'a', 'b', 'c', 'c', 'd'},
        {'a', 'a', 'a', 'a', 'a'},
        {'a', 'b', 'a', 'b', 'z'}
    };
    
    char firstSorted[rows][columns] = {
        {'a', 'a', 'p', 'q', 'z'},
        {'a', 'a', 'b', 'b', 'c'},
        {'a', 'b', 'c', 'c', 'd'},
        {'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'b', 'b', 'z'}
    };
    
    sortRow(first, 0);
    
    for (int i = 0; i < 5; i++){
        REQUIRE(first[0][i] == firstSorted[0][i]);
    }
}

TEST_CASE("Testing sortRow() - 2"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'a', 'q', 'a', 'z', 'p'},
        {'b', 'a', 'b', 'a', 'c'},
        {'a', 'b', 'c', 'c', 'd'},
        {'a', 'a', 'a', 'a', 'a'},
        {'a', 'b', 'a', 'b', 'z'}
    };
    
    char firstSorted[rows][columns] = {
        {'a', 'a', 'p', 'q', 'z'},
        {'a', 'a', 'b', 'b', 'c'},
        {'a', 'b', 'c', 'c', 'd'},
        {'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'b', 'b', 'z'}
    };
    
    for (int i = 0; i < 5; i++){
        sortRow(first, i);
    }
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            REQUIRE(first[i][j] == firstSorted[i][j]);
        }
    }
}

TEST_CASE("Testing sortColumn() - 1"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'a', 'q', 'a', 'z', 'p'},
        {'b', 'a', 'b', 'a', 'c'},
        {'a', 'b', 'c', 'c', 'd'},
        {'a', 'a', 'a', 'a', 'a'},
        {'a', 'b', 'a', 'b', 'z'}
    };
    
    char firstSorted[rows][columns] = {
        {'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'c'},
        {'a', 'b', 'a', 'b', 'd'},
        {'a', 'b', 'b', 'c', 'p'},
        {'b', 'q', 'c', 'z', 'z'}
    };
    
    sortColumn(first, 0);
    
    for (int i = 0; i < rows; i++){
        REQUIRE(first[i][0] == firstSorted[i][0]);
    }
}

TEST_CASE("Testing sortColumn() - 2"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'a', 'q', 'a', 'z', 'p'},
        {'b', 'a', 'b', 'a', 'c'},
        {'a', 'b', 'c', 'c', 'd'},
        {'a', 'a', 'a', 'a', 'a'},
        {'a', 'b', 'a', 'b', 'z'}
    };
    
    char firstSorted[rows][columns] = {
        {'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'c'},
        {'a', 'b', 'a', 'b', 'd'},
        {'a', 'b', 'b', 'c', 'p'},
        {'b', 'q', 'c', 'z', 'z'}
    };
    
    for (int i = 0; i < 5; i++){
        sortColumn(first, i);
    }
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            REQUIRE(first[i][j] == firstSorted[i][j]);
        }
    }
}

TEST_CASE("Testing both sorts"){
    const unsigned int rows = 5;
    const unsigned int columns = 5;
    
    char first[rows][columns] = {
        {'a', 'q', 'a', 'z', 'p'},
        {'b', 'a', 'b', 'a', 'c'},
        {'a', 'b', 'c', 'c', 'd'},
        {'a', 'a', 'a', 'a', 'a'},
        {'a', 'b', 'a', 'b', 'z'}
    };
    
    char firstSorted[rows][columns] = {
        {'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'c'},
        {'a', 'a', 'b', 'b', 'd'},
        {'a', 'b', 'b', 'c', 'p'},
        {'b', 'c', 'q', 'z', 'z'}
    };
    
    for (int i = 0; i < 5; i++){
        sortColumn(first, i);
    }
    
    for (int i = 0; i < 5; i++){
        sortRow(first, i);
    }
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            REQUIRE(first[i][j] == firstSorted[i][j]);
        }
    }
}
