#ifndef solver_h
#define solver_h

#include <iostream>
#include <stdlib.h>

using namespace std;

enum BitType
{
    Maze,
    Path
};
short mazeRows[16]; // Our Maze
short pathRows[16]; // Our Followed Path

void inputTestData(short data[]) // Get User Input from main.cpp
{
    for (int i = 0; i < 16; i++)
    {
        mazeRows[i] = data[i];
    }
}

short getBit(BitType type, int x, int y) // Reads a bit at given x / y value
{

    if (type == Maze)
    {
        if (((mazeRows[y]) & (1 << (15 - x))) < 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (((pathRows[y]) & (1 << (15 - x))) < 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

void setPathBit(int x, int y) { pathRows[y] = (pathRows[y] | ((1 << (15 - x)))); } // Sets the bit at x/y to a 1

void clearPath() //Resets Path
{
    for (int i = 0; i < 16; i++)
    {
        pathRows[i] = 0;
    }
}

bool move(int x, int y)
{

    setPathBit(x, y);

    if ((x == 15) && (y == 15))
    {
        return true;
    }

    if (((getBit(Maze, x + 1, y)) == 0) && ((getBit(Path, x + 1, y)) == 0) && (x < 15)) //right
    {
        if (move(x + 1, y))
        {
            return true;
        }
    }

    if (((getBit(Maze, x, y + 1)) == 0) && ((getBit(Path, x, y + 1)) == 0) && (y < 15)) //down
    {
        if (move(x, y + 1))
        {
            return true;
        }
    }

    if (((getBit(Maze, x - 1, y)) == 0) && ((getBit(Path, x - 1, y)) == 0) && (x > 0)) //left
    {
        if (move(x - 1, y))
        {
            return true;
        }
    }

    if (((getBit(Maze, x, y - 1)) == 0) && ((getBit(Path, x, y - 1)) == 0) && (y > 0)) //up
    {
        if (move(x, y - 1))
        {
            return true;
        }
    }

    pathRows[y] = ~((~pathRows[y]) | (1 << (15 - x)));
    return false;
}

void showMaze()
{
    if (getBit(Path, 15, 15) == 1)
    {
        for (int i = 0; i < 16; i++) // rows
        {
            for (int j = 0; j < 16; j++) // columns
            {
                if ((getBit(Maze, j, i) == 0) && (getBit(Path, j, i) == 1))
                {
                    cout << " 1";
                }
                else
                {
                    cout << " " << getBit(Path, j, i);
                }
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < 16; i++)
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