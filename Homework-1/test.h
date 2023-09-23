#ifndef solver_h
#define solver_h

#include <iostream>
#include <stdlib.h>

using namespace std; 

enum BitType { Maze, Path };
short mazeRows[16];
short pathRows[16];

// Takes in values to put into the array.
void inputTestData(short data[]) {for (int i = 0; i < 16; i++) {mazeRows[i] = data[i];}}

// Reads the bit depending on the parameters
short getBit(BitType type, int x, int y) {

    if (type == Maze) {
        if (((mazeRows[y]) & (1 << (15 - x))) < 1) { return 0;}
        else { return 1;}
    }
    else {
        if (((pathRows[y]) & (1 << (15 - x))) < 1){ return 0;}
        else {return 1;}
    }
}

void setPathBit(int x, int y){ pathRows[y] = (pathRows[y] | ((1 << (15 - x))));}

void clearPath() { for (int i = 0; i < 16; i++) {pathRows[i] = 0;}}

bool move(int x, int y) {
    setPathBit(x, y);    

    if ((x == 15) && (y==15)){ return true;} // Base Case

    if (((getBit(Maze, x + 1, y)) == 0) && ((getBit(Path, x + 1, y)) == 0) && (x < 15)){ return move(x + 1, y);} // Right

    if (((getBit(Maze, x, y + 1)) == 0) && ((getBit(Path, x, y + 1)) == 0) && (y < 15)){ return move(x, y + 1);} // Down

    if (((getBit(Maze, x - 1, y)) == 0) && ((getBit(Path, x-1, y)) == 0) && (x > 0)){ return move(x-1, y);} // Left
    
    if (((getBit(Maze, x, y-1)) == 0) && ((getBit(Path, x, y-1)) == 0) && (y > 0)){ return move(x, y-1);} // Up
   
    pathRows[y] = ~((~pathRows[y]) | (1 << (15 - x))); // Unmark
    return false;
}

void showMaze() {
    if (getBit(Path, 15, 15) == 1) // Chacks to see if it has been solved
    {
        for (int i = 0; i < 16; i++) // Cycles through rows
        {
            for (int j = 0; j < 16; j++) // Cycle through columns
            {
                if((getBit(Maze, j, i) == 0) && (getBit(Path, j, i) == 1))
                {
                    cout << " 1";
                }
                else
                {
                    cout << " " << getBit(Path, j, i); // Prints out which ever bit it reads
                }

            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < 16; i++) // If not solved then it cycles through each row and reads the bit from each element of the row and then prints it.
        {
            for (int j = 0; j < 16; j++)
            {
                cout << " " << getBit(Path, j, i);
            }
            cout << endl;
        }
    }
}

#endif