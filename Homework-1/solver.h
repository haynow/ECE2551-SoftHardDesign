
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
#include <array>

using namespace std;

enum BitType { Maze, Path};

short mazeRows[16] = {0};
short pathRows[16] = {0};
short actualMaze[16][16];

BitType bit1 = Maze;
BitType bit2 = Path;


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
   
   
   return -1; }

void setPathBit(int x, int y) {}

void clearPath() {}

bool move(int x, int y) { return false; }

void showMaze() {}



#endif /* solver_h */
