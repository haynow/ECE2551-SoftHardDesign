// solver.h
#ifndef solver_h
#define solver_h

#include <iostream>
#include <array>
#include <bitset>

using namespace std;

enum BitType { Maze, Path };

const int MAZE_SIZE = 16;
short mazeRows[MAZE_SIZE];
short pathRows[MAZE_SIZE];
bitset<MAZE_SIZE> actualMaze[MAZE_SIZE];

void inputTestData(short data[]) {
   for(int i = 0; i < sizeof(data); i++){
      int binaryNum[32];
 
      // counter for binary array
      int n = data[i];
      int j = 0;
      while (j > 0) {
   
         // storing remainder in binary array
         binaryNum[j] = n % 2;
         n = n / 2;
         j++;
      }

      for (int k = 0; k < sizeof(binaryNum); k++){
         actualMaze[i][k] = binaryNum[k];
      }
   }
}

short getBit(BitType type, int x, int y) {
    if (x < 0 || x >= MAZE_SIZE || y < 0 || y >= MAZE_SIZE) {
        return -1; // Out of bounds
    }
    if (type == Maze) {
        return actualMaze[y][x] ? 1 : 0;
    } else {
        return pathRows[y] & (1 << (MAZE_SIZE - 1 - x)) ? 1 : 0;
    }
}

void setPathBit(int x, int y) {
    if (x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE) {
        pathRows[y] |= (1 << (MAZE_SIZE - 1 - x));
    }
}

void clearPath() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        pathRows[i] = 0;
    }
}

bool move(int x, int y) { 
   
   setPathBit(x, y);

//Is maze solved?
if ((x == 15)&&(y==15))
{
   return true;
}

//right
if (((getBit(Maze, x + 1, y)) == 0) && ((getBit(Path, x + 1, y)) == 0))  // If you CAN move
{
      if (x < 15)
      {
         if (move(x + 1, y)) //move
         {
            return true;
         }
      }
}

//down
if (((getBit(Maze, x, y + 1)) == 0) && ((getBit(Path, x, y + 1)) == 0)) // If you CAN move
{
      if (x < 15)
      {
         if (move(x, y + 1)) //move
         {
            return true;
         }
      }
}

//left
if (((getBit(Maze, x - 1, y)) == 0) && ((getBit(Path, x - 1, y)) == 0)) // If you CAN move
{
      if (x < 15)
      {
         if (move(x - 1, y)) //move
         {
            return true;
         }
      }
}

//up
if (((getBit(Maze, x, y - 1)) == 0) && ((getBit(Path, x, y - 1)) == 0)) // If you CAN move
{
      if (x < 15)
      {
         if (move(x, y - 1)) //move
         {
            return true;
         }
      }
}

}

void showMaze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (pathRows[i] & (1 << (MAZE_SIZE - 1 - j))) {
                cout << "* ";
            } else {
                cout << actualMaze[i][j] << " ";
            }
        }
        cout << endl;
    }
}

#endif /* solver_h */
