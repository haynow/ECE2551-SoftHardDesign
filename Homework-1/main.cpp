#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "solver.h"
#include <bitset>

TEST_CASE("First Maze", "[maze1]")
{
   short test[16] = {8704, static_cast<short>(43967), static_cast<short>(43904), static_cast<short>(35774), static_cast<short>(54184), 21419, 24456, 18366, 30114, static_cast<short>(55208), 30639, 1967, 32303, 16543, 5824, static_cast<short>(62206)};

   short pathTest[16] = {static_cast<short>(49152), 16384, 16384, 24576, 8192, 8192, 8192, 14336, 2048, 2048, 2048, static_cast<short>(63488), static_cast<short>(33216), static_cast<short>(48992), static_cast<short>(57407), 1};

   // Testing that mazeRows is a 16 element array of type short.
   REQUIRE(sizeof(mazeRows) == 32);
   REQUIRE(sizeof(pathRows) == 32);

   // Testing input data.
   inputTestData(test);
   for (int i = 0; i < 16; i++)
   {
      REQUIRE(mazeRows[i] == test[i]);
   }

   // Testing get bit operations
   std::bitset<16> testRow;
   for (int y = 0; y < 16; y++)
   {
      testRow = std::bitset<16>(test[y]);
      for (int x = 0; x < 16; x++)
      {
         REQUIRE(bool(getBit(Maze, x, y)) == testRow[15 - x]);
      }
   }

   // Testing set bit operations
   testRow = std::bitset<16>(std::string("1111111111111111"));
   for (int y = 0; y < 16; y++)
   {
      setPathBit(0, y);
      REQUIRE(bool(getBit(Path, 0, y)) == testRow[15 - y]);
   }

   // Testing clearing of path data.
   clearPath();
   for (int i = 0; i < 16; i++)
   {
      REQUIRE(pathRows[i] == 0);
   }

   // Testing for solution
   bool solvable = move(0, 0);
   REQUIRE(solvable == true);

   if (solvable == true)
   {
      std::bitset<16> pathRow;
      for (int i = 0; i < 16; i++)
      {
         pathRow = std::bitset<16>(pathTest[i]);
         testRow = std::bitset<16>(pathRows[i]);
         for (int j = 0; j < 16; j++)
         {
            REQUIRE(pathRow[j] == testRow[j]);
         }
      }

      std::cout << "Maze #1 Solution: "
                << "Solved!\n"
                << std::endl;
      showMaze();
      std::cout << std::endl;
   }
   else
   {
      std::cout << "Maze #1 Solution: "
                << "No Solution\n"
                << std::endl;
   }
}

TEST_CASE("Second Maze", "[maze2]")
{
   short test[16] = {31745, 1365, 17749, static_cast<short>(58709), 30718, static_cast<short>(45242), 29883, static_cast<short>(46779), 28672, static_cast<short>(47018), 30666, static_cast<short>(46122), 31798, static_cast<short>(65530), static_cast<short>(32768), static_cast<short>(49150)};

   short pathTest[16] = {static_cast<short>(32768), static_cast<short>(63488), 2048, 2048, 2048, 3840, 256, 256, 511, 1, 1, 1, 1, 1, 1, 1};

   // Testing that mazeRows is a 16 element array of type short.
   REQUIRE(sizeof(mazeRows) == 32);
   REQUIRE(sizeof(pathRows) == 32);

   // Testing input data.
   inputTestData(test);
   for (int i = 0; i < 16; i++)
   {
      REQUIRE(mazeRows[i] == test[i]);
   }

   // Testing get bit operations
   std::bitset<16> testRow;
   for (int y = 0; y < 16; y++)
   {
      testRow = std::bitset<16>(test[y]);
      for (int x = 0; x < 16; x++)
      {
         REQUIRE(bool(getBit(Maze, x, y)) == testRow[15 - x]);
      }
   }

   // Testing set bit operations
   testRow = std::bitset<16>(std::string("1111111111111111"));
   for (int y = 0; y < 16; y++)
   {
      setPathBit(0, y);
      REQUIRE(bool(getBit(Path, 0, y)) == testRow[15 - y]);
   }

   // Testing clearing of path data.
   clearPath();
   for (int i = 0; i < 16; i++)
   {
      REQUIRE(pathRows[i] == 0);
   }

   // Testing for solution
   bool solvable = move(0, 0);
   REQUIRE(solvable == true);

   if (solvable == true)
   {
      std::bitset<16> pathRow;
      
      for (int i = 0; i < 16; i++)
      {
         pathRow = std::bitset<16>(pathTest[i]);
         testRow = std::bitset<16>(pathRows[i]);
         for (int j = 0; j < 16; j++)
         {
            REQUIRE(pathRow[j] == testRow[j]);
         }
      }

      std::cout << "Maze #2 Solution: "
                << "Solved!\n"
                << std::endl;
      showMaze();
      std::cout << std::endl;
   }
   else
   {
      std::cout << "Maze #2 Solution: "
                << "No Solution\n"
                << std::endl;
   }
}

TEST_CASE("Third Maze", "[maze3]")
{
   short test[16] = {static_cast<short>(34952), 4369, 8738, 17476, static_cast<short>(39321), 8738, 17476, static_cast<short>(39321), 8738, 17476, static_cast<short>(34952), 0, static_cast<short>(65535), 26214, static_cast<short>(39321), static_cast<short>(39321)};

   short pathTest[16] = {static_cast<short>(32768), static_cast<short>(63488), 2048, 2048, 2048, 3840, 256, 256, 511, 1, 1, 1, 1, 1, 1, 1};

   // Testing that mazeRows is a 16 element array of type short.
   REQUIRE(sizeof(mazeRows) == 32);
   REQUIRE(sizeof(pathRows) == 32);

   // Testing input data.
   inputTestData(test);
   for (int i = 0; i < 16; i++)
   {
      REQUIRE(mazeRows[i] == test[i]);
   }

   // Testing get bit operations
   std::bitset<16> testRow;
   for (int y = 0; y < 16; y++)
   {
      testRow = std::bitset<16>(test[y]);
      for (int x = 0; x < 16; x++)
      {
         REQUIRE(bool(getBit(Maze, x, y)) == testRow[15 - x]);
      }
   }

   // Testing set bit operations
   testRow = std::bitset<16>(std::string("1111111111111111"));
   for (int y = 0; y < 16; y++)
   {
      setPathBit(0, y);
      REQUIRE(bool(getBit(Path, 0, y)) == testRow[15 - y]);
   }

   // Testing clearing of path data.
   clearPath();
   for (int i = 0; i < 16; i++)
   {
      REQUIRE(pathRows[i] == 0);
   }

   // Testing for solution
   bool solvable = move(0, 0);
   REQUIRE(solvable == false);

   if (solvable == true)
   {
      std::bitset<16> pathRow;
      for (int i = 0; i < 16; i++)
      {
         pathRow = std::bitset<16>(pathTest[i]);
         testRow = std::bitset<16>(pathRows[i]);
         for (int j = 0; j < 16; j++)
         {
            REQUIRE(pathRow[j] == testRow[j]);
         }
      }

      std::cout << "Maze #3 Solution: "
                << "\n"
                << std::endl;
      showMaze();
      std::cout << std::endl;
   }
   else
   {
      std::cout << "Maze #3 Solution: "
                << "No Solution\n"
                << std::endl;
   }
}

TEST_CASE("Fourth Maze", "[maze4]")
{
   short test[16] = {8704, static_cast<short>(43967), static_cast<short>(43904), static_cast<short>(35774), static_cast<short>(54184), 21419, 24456, 18366, 30114, static_cast<short>(55208), 30639, 1967, 32303, 16543, 5824, static_cast<short>(62207)};

   short pathTest[16] = {static_cast<short>(49152), 16384, 16384, 24576, 8192, 8192, 8192, 14336, 2048, 2048, 2048, static_cast<short>(63488), static_cast<short>(33216), static_cast<short>(48992), static_cast<short>(57407), 1};

   // Testing that mazeRows is a 16 element array of type short.
   REQUIRE(sizeof(mazeRows) == 32);
   REQUIRE(sizeof(pathRows) == 32);

   // Testing input data.
   inputTestData(test);
   for (int i = 0; i < 16; i++)
   {
      REQUIRE(mazeRows[i] == test[i]);
   }

   // Testing get bit operations
   std::bitset<16> testRow;
   for (int y = 0; y < 16; y++)
   {
      testRow = std::bitset<16>(test[y]);
      for (int x = 0; x < 16; x++)
      {
         REQUIRE(bool(getBit(Maze, x, y)) == testRow[15 - x]);
      }
   }

   // Testing set bit operations
   testRow = std::bitset<16>(std::string("1111111111111111"));
   for (int y = 0; y < 16; y++)
   {
      setPathBit(0, y);
      REQUIRE(bool(getBit(Path, 0, y)) == testRow[15 - y]);
   }

   // Testing clearing of path data.
   clearPath();
   for (int i = 0; i < 16; i++)
   {
      REQUIRE(pathRows[i] == 0);
   }
   
   // Testing for solution
   bool solvable = move(0, 0);
   REQUIRE(solvable == false);

   if (solvable == true)
   {
      std::bitset<16> pathRow;
      for (int i = 0; i < 16; i++)
      {
         pathRow = std::bitset<16>(pathTest[i]);
         testRow = std::bitset<16>(pathRows[i]);
         for (int j = 0; j < 16; j++)
         {
            REQUIRE(pathRow[j] == testRow[j]);
         }
      }

      std::cout << "Maze #4 Solution: "
                << "Solved!\n"
                << std::endl;
      showMaze();
      std::cout << std::endl;
   }
   else {
      std::cout << "Maze #4 Solution: " << "No Solution\n" << std::endl;
   }
}
