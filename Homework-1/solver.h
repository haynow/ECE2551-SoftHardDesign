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

//Step 5
enum BitType {
    Maze,
    Path
};
int main() {
// Step 3    
    short mazeRows[16] = {0}; 

   
    mazeRows[0] = 1; 

    for (int i = 0; i < 16; i++) {
        std::cout << "mazeRows[" << i << "] = " << mazeRows[i] << std::endl;
    }
//------------------------------------------------------------------
// Step 4
  short pathRows[16] = {0}; 

   
    pathRows[0] = 1; 
    pathRows[3] = 1; 

    
    for (int i = 0; i < 16; i++) {
        std::cout << "pathRows[" << i << "] = " << pathRows[i] << std::endl;
    }
//-------------------------------------------------------------------
//Step 5 
 BitType bit1 = Maze;
    BitType bit2 = Path;

    std::cout << "bit1: " << bit1 << std::endl;
    std::cout << "bit2: " << bit2 << std::endl;
//--------------------------------------------------------------------

    return 0;
}

void inputTestData(short data[]){

}

short getBit(BitType type, int x, int y){
   return -1;
}

void setPathBit(int x, int y){
   
}

void clearPath(){

}

bool move(int x, int y){
   return false;
}

void showMaze(){
   
}

#endif /* solver_h */
