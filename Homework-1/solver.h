
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

using namespace std;

// Step 5

enum BitType { Maze, Path};

short mazeRows[16] = {0};
short pathRows[16] = {0};

BitType bit1 = Maze;
BitType bit2 = Path;

void inputTestData(short data[]) {}

short getBit(BitType type, int x, int y) { return -1; }

void setPathBit(int x, int y) {}

void clearPath() {}

bool move(int x, int y) { return false; }

void showMaze() {}

#endif /* solver_h */
 // hi
 