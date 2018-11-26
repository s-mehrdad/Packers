// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,26.11.2018</changed>
// ********************************************************************************

#include "pch.h"
#include "Area.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Packer.h"
#include "Surround.h"


struct Area::materials {
  struct walls {
    std::string hWalls { u8"━" };
    std::string vWalls { u8"┃" };
    std::string edges[4] { u8"┏",u8"┗",u8"┛",u8"┓" };
    WORD colour { F_bPURPLE };
  } _walls;

  struct resources {
    std::string pack { u8"♣" };
    WORD colourOne { F_bGREEN };
    WORD colourTwo { F_YELLOW };
    WORD colourTree { F_bRED };
  } _resources;
} _materials;


Area::Area (unsigned char mode, unsigned char height, unsigned char width) :rows (height), columns (width) {

  COORD position;
  for (int y = 1; y <= rows; y++) {
    for (int x = 1; x <= columns; x++) {
      position.X = x;
      position.Y = y;
      colourInserter (position);

      // first horizontal wall
      if (y == 1 && x != columns) {

        // left top edge
        if (y == 1 && x == 1)
          colourInserter (_materials._walls.edges[0], _materials._walls.colour);
        colourInserter (_materials._walls.hWalls, _materials._walls.colour);
      }

      // right top edge
      if (y == 1 && x == columns)
        colourInserter (_materials._walls.edges[3], _materials._walls.colour);

      // left bottom edge
      if (y == rows && x == 1)
        colourInserter (_materials._walls.edges[1], _materials._walls.colour);

      // second horizontal wall
      if (y == rows && x != columns)
        colourInserter (_materials._walls.hWalls, _materials._walls.colour);
      else
        // right bottom edge
        if (y == rows && x == columns)
          colourInserter (_materials._walls.edges[2], _materials._walls.colour);
        else

          // vertical walls
          if (x == 1 || x == columns)
            if (y != 1)
              colourInserter (_materials._walls.vWalls, _materials._walls.colour);

      if (mode == 0) {
        // packs
        if (y != 1 && y != rows && y % 2 == 0)
          if (x != 1 && x != columns && x % 2 == 0)
            //if (j!=11&&j!=99)
            colourInserter (_materials._resources.pack, _materials._resources.colourOne);
      }
      std::cout << '\n';
    }
  }
};
//Area(//userchoice) :rows (),columns() {};


void Area::green (COORD position) {
  //int y = position.Y;
  //int x = position.X;
  //if (x - 1 != 2) {
  //  do {} while (protectedSetCursor == true);
  //  protectedSetCursor = true;
  //  gotoXY (x - 1, y - 1); ColourCout (u8"♣", F_bGREEN);
  //  protectedSetCursor = false;
  //  do {} while (protectedSetCursor == true);
  //  protectedSetCursor = true;
  //  gotoXY (x - 1, y + 1); ColourCout (u8"♣", F_bGREEN);
  //  protectedSetCursor = false;
  //}
  //if (x + 1 != 88) {
  //  do {} while (protectedSetCursor == true);
  //  protectedSetCursor = true;
  //  gotoXY (x + 1, y + 1); ColourCout (u8"♣", F_bGREEN);
  //  protectedSetCursor = false;
  //  do {} while (protectedSetCursor == true);
  //  protectedSetCursor = true;
  //  gotoXY (x + 1, y - 1); ColourCout (u8"♣", F_bGREEN);
  //  protectedSetCursor = false;
  //}
  //if (y - 1 != 2) {
  //  do {} while (protectedSetCursor == true);
  //  protectedSetCursor = true;
  //  gotoXY (x - 1, y - 1); ColourCout (u8"♣", F_bGREEN);
  //  protectedSetCursor = false;
  //  do {} while (protectedSetCursor == true);
  //  protectedSetCursor = true;
  //  gotoXY (x + 1, y - 1); ColourCout (u8"♣", F_bGREEN);
  //  protectedSetCursor = false;
  //}
  //if (y + 1 != 18) {
  //  do {} while (protectedSetCursor == true);
  //  protectedSetCursor = true;
  //  gotoXY (x - 1, y + 1); ColourCout (u8"♣", F_bGREEN);
  //  protectedSetCursor = false;
  //  do {} while (protectedSetCursor == true);
  //  protectedSetCursor = true;
  //  gotoXY (x + 1, y + 1); ColourCout (u8"♣", F_bGREEN);
  //  protectedSetCursor = false;
  //}
}
void Area::yellow (COORD position) {}
void Area::red (COORD position) {}
void Area::fullPacked () {}


void Area::colourInserter (COORD pos) {
  SetConsoleCursorPosition (consoleOutput, pos);
};


void Area::colourInserter (std::string str, WORD colour) {
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  SetConsoleTextAttribute (consoleOutput, colour);
  std::cout << str;
};