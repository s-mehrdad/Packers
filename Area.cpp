// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,14.11.2018</changed>
// ********************************************************************************

#include "pch.h"
#include "Area.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Packer.h"
#include "Surround.h"


struct Area::materials {
  std::string hWalls { u8"━" };
  std::string vWalls { u8"┃" };
  std::string edges[4] { u8"┏",u8"┗",u8"┛",u8"┓" };
  std::string pack { u8"♣" };
} stuff;


Area::Area (unsigned char mode) :rows (19), columns (89) {

  for (int y = 1; y <= 19; y++) {
    for (int x = 1; x <= 89; x++) {
      gotoXY (x, y);

      // first horizontal wall
      if (y == 1 && x != 89) {

        // left top edge
        if (y == 1 && x == 1)
          ColourCout (stuff.edges[0], F_bPURPLE);
        ColourCout (stuff.hWalls, F_bPURPLE);
      }

      // right top edge
      if (y == 1 && x == 89)
        ColourCout (stuff.edges[3], F_bPURPLE);

      // left bottom edge
      if (y == 19 && x == 1)
        ColourCout (stuff.edges[1], F_bPURPLE);

      // second horizontal wall
      if (y == 19 && x != 89)
        ColourCout (stuff.hWalls, F_bPURPLE);
      else
        // right bottom edge
        if (y == 19 && x == 89)
          ColourCout (stuff.edges[2], F_bPURPLE);
        else

          // vertical walls
          if (x == 1 || x == 89)
            if (y != 1)
              ColourCout (stuff.vWalls, F_bPURPLE);

      if (mode == 0) {
        // packs
        if (y != 1 && y != 19 && y % 2 == 0)
          if (x != 1 && x != 89 && x % 2 == 0)
            //if (j!=11&&j!=99)
            ColourCout (stuff.pack, F_bGREEN);
      }
      std::cout << u8"\n";
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