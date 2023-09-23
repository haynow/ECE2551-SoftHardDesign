//
//  solver.h
//  MazeSolverM
//
//  Created by Xavier Merino on 8/28/16.
//  Copyright © 2016 Xavier Merino. All rights reserved.
//
 using namespace std;
#ifndef solver_h
#define solver_h

#include <iostream>
#include <stdlib.h>
#include <array>

enum BitType
{
    Maze,
    Path
};

const int SIZE_OF_MATH = 16;
short mazeRows[SIZE_OF_MATH];
short pathRows[SIZE_OF_MATH];
short workingBinaryNum[16];

void short_to_bin(short number) // Convert s a given short to a binary array, sets workingBinary to said array
{
    int reverseBinaryNumber[16];

    // counter for binary array
    int n = (int)number;
    int j = 0;
    while (j > 0)
    {
    // storing remainder in binary array
    reverseBinaryNumber[j] = n % 2;
    n = n / 2;
    j++;
    }

    for (int i = 0; i < 32; i++){
        workingBinaryNum[i] = reverseBinaryNumber[31-i];
    }
}

short bin_to_short (){  //Converts Binary number array to a string binary number then converts to a short (base 10)
    string binOfString;
    for (int i = 0; i < 16; i++){
        binOfString += to_string(workingBinaryNum[i]);
    }
    short convertedNum = stoi(binOfString, nullptr, 2);
    return convertedNum;
} 

void inputTestData(short data[]) // Gets Input From Driver File and Saves the data to mazeRows
{
    for (int i = 0; i < SIZE_OF_MATH; i++)
    {
        mazeRows[i] = data[i];
        pathRows[i] = 0;
    }

}

short getBit(BitType type, int x, int y)
{
    if (type == Maze){
        short_to_bin(mazeRows[x]);
        return workingBinaryNum[y];
    }

    else {
        short_to_bin(pathRows[x]);
        return workingBinaryNum[y];
    }
}

void setPathBit(int x, int y){
    short_to_bin(pathRows[x]);
    workingBinaryNum[y] = 1;
    pathRows[x] = bin_to_short();
}

void clearPath(){ // Sets whole array to 0
    for (int i = 0; i < 16; i++){
        pathRows[i] = 0;
    }
}

bool move(int x, int y)
{
    if (x == 15 && y == 15){
        setPathBit(x,y);
        return true;
    }

    if (x < 15){
        if (getBit(Maze, x + 1,y) == 0){ // Right
            if (move (x + 1, y)){
                setPathBit(x + 1, y);
            }
        }
    }

    if (y < 15){
        if (getBit(Maze, x, y + 1) == 0){ // Down
            if (move (x, y + 1)){
                setPathBit(x, y + 1);
            }
        }
    }

    if (x > 0){
        if (getBit(Maze, x - 1,y) == 0){ // Left
            if (move (x - 1, y)){
                setPathBit(x - 1, y);
            }
        }
    }

    if (y > 0){
        if (getBit(Maze, x, y - 1) == 0){ // Down
            if (move (x, y - 1)){
                setPathBit(x, y - 1);
            }
        }
    }

    // Add base case
    return false;

}


void showMaze(){ // Prints Full Mazw to standard output stream (STD)
    for (int j = 0; j < 16; j++){
        // Rows
        short_to_bin(mazeRows[j]);
        for (int i = 0; i < 16; i++){ // Columns
            cout << workingBinaryNum[i];  
        }
        cout << endl;
    }

}


#endif /* solver_h */
