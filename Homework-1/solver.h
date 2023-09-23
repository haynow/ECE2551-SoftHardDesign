//
//  solver.h
//  MazeSolverM
//
//  Created by Xavier Merino on 8/28/16.
//  Copyright © 2016 Xavier Merino. All rights reserved.
//

#ifndef solver_h
#define solver_h

#include <iostream>
#include <stdlib.h>

short mazeRows[16];
short pathRows[16];
enum BitType{value1,value2}; 

void inputTestData(short data[]){

}

short getBit(BitType type, int x, int y){
    return -1;
}

void setPathBit(int x, int y){
   
}

void clearPath(){

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
