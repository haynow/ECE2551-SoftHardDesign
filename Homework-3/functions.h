//
//  functions.h
//  Pointers
//
//

#ifndef functions_h
#define functions_h

#include <iostream>

using namespace std;
const int arraySize = 5;

char getCharacter(char (*array)[arraySize], int row, int column);
char* getCharacterAddress(char (*array)[arraySize], int row, int column);
void getRow(char(*array)[arraySize], int row, char* resultArray);
void getColumn(char(*array)[arraySize], int column, char* resultArray);
void insertionSort(char data[], int size);
void sortRow(char(*array)[arraySize], int row);
void sortColumn(char(*array)[arraySize], int column);

#endif /* functions_h */
