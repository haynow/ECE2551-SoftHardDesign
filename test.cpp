#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>

short mazeRows[16] = {0};
short pathRows[16] = {0};

enum BitType {
    Maze,
    Path
};

void inputTestData(short data[]) {
    for (int i = 0; i < 16; i++) {
        mazeRows[i] = data[i];
    }
}

short getBit(BitType type, int x, int y) {
    short* sourceArray = (type == Maze) ? mazeRows : pathRows;
    return (sourceArray[y] >> (15 - x)) & 1;
}

void setPathBit(int x, int y) {
    pathRows[y] |= (1 << (15 - x));
}

void clearPathBit(int x, int y) {
    pathRows[y] &= ~(1 << (15 - x));
}

void clearPath() {
    for (int i = 0; i < 16; i++) {
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
return false;
}

void showMaze() {
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
            if (getBit(Path, x, y) == 1) {
                std::cout << "* ";
            } else {
                std::cout << (getBit(Maze, x, y) ? "1 " : "0 ");
            }
        }
        std::cout << std::endl;
    }
}

#endif // SOLVER_H