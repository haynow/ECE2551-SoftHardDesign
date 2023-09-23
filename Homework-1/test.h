#ifndef solver_h
#define solver_h

#include <iostream>
#include <stdlib.h>

enum BitType { Maze, Path };
short mazeRows[16];
short pathRows[16];

// Takes in values to put into the array.
void inputTestData(short data[]) {
    for (int i = 0; i < 16; i++) {
        mazeRows[i] = data[i];
    }
}

// Reads the bit depending on the parameters
short getBit(BitType type, int x, int y) {

    short value;

    if (type == Maze) {
        if (((mazeRows[y]) & (1 << (15 - x))) < 1) // Checks to see if the value masked from the row is less than one
        {
            value = 0;
        }
        else    // If it is greater than one, it assigns one to value.
        {
            value = 1;
        }
    }
    if (type == Path) {
        if (((pathRows[y]) & (1 << (15 - x))) < 1)
        {
            value = 0;
        }
        else
        {
            value = 1;
        }
       
    }
    return value;
}

void setPathBit(int x, int y) // Marks the bit
{
   
    pathRows[y] = (pathRows[y] | ((1 << (15 - x))));
   
 
}
// Cycles through each row making the value of each short zero, so the row is a row of zeroes.
void clearPath() {
    for (int i = 0; i < 16; i++) {
        pathRows[i] = 0;
    }

}

bool move(int x, int y) {
   

    // Begins by marking the bit.
    setPathBit(x, y);    

    // Checks to see if the last entry has been marked, which meaans is the maze solved?
    if ((x == 15)&&(y==15))    // If it is solved, it returns true.
    {
        return true;
    }
    //===============================================================================================================================
    // Not solved
    if (((getBit(Maze, x + 1, y)) == 0) && ((getBit(Path, x + 1, y)) == 0)) // Can move right?
    {
        if (x < 15) // Within maze
        {
            if (move(x + 1, y))  //Check to see if next space can move
            {
                return true;
            }
           
        }
    }
    //================================================================================================================================

    if (((getBit(Maze, x, y + 1)) == 0) && ((getBit(Path, x, y + 1)) == 0)) //Can move down?
    {
        if (y < 15) // Within maze
        {
            if (move(x, y + 1)) // Check to see if next space can move
            {
                return true;
            }
           
        }
    }
    //=================================================================================================================================

    if (((getBit(Maze, x - 1, y)) == 0) && ((getBit(Path, x - 1, y)) == 0)) // Can move left?
    {
        if (x > 0) // Within maze
        {
            if (move(x - 1, y)) // Checks to see if next space can move
            {
                return true;
            }
           
        }
    }
    //=================================================================================================================================

    if (((getBit(Maze, x, y - 1)) == 0) && ((getBit(Path, x, y - 1)) == 0)) // Can move up?
    {
        if (y > 0)
        {
            if (move(x, y - 1)) // Checks to see if next space can move
            {
                return true;
            }

        }
    }
    //==================================================================================================================================
   
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
                if((getBit(Maze, j, i) == 0) && (getBit(Path, j, i) == 1)) // If the maze value is different from the path value, then it prints a star.
                {
                    std::cout << " *";
                }
                else
                {
                    std::cout << " " << getBit(Maze, j, i); // Prints out which ever bit it reads
                }

            }
            std::cout << std::endl;
        }
    }
    else
    {
        for (int i = 0; i < 16; i++) // If not solved then it cycles through each row and reads the bit from each element of the row and then prints it.
        {
            for (int j = 0; j < 16; j++)
            {
                std::cout << " " << getBit(Path, j, i);
            }
            std::cout << std::endl;
        }
    }

   
       
   

}

#endif