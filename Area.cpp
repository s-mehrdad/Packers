

#include "pch.h"
#include "Area.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Packer.h"


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
          std::cout << stuff.edges[0];
        std::cout << stuff.hWalls;
      }

      // right top edge
      if (y == 1 && x == 89)
        std::cout << stuff.edges[3];

      // left bottom edge
      if (y == 19 && x == 1)
        std::cout << stuff.edges[1];

      // second horizontal wall
      if (y == 19 && x != 89)
        std::cout << stuff.hWalls;
      else
        // right bottom edge
        if (y == 19 && x == 89)
          std::cout << stuff.edges[2];
        else

          // vertical walls
          if (x == 1 || x == 89)
            if (y != 1)
              std::cout << stuff.vWalls;

      if (mode == 1) {
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
  int y = position.Y;
  int x = position.X;
  if (x - 1 != 2) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y - 1); ColourCout (u8"♣", F_bGREEN);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y + 1); ColourCout (u8"♣", F_bGREEN);
    protectedSetCursor = false;
  }
  if (x + 1 != 88) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y + 1); ColourCout (u8"♣", F_bGREEN);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y - 1); ColourCout (u8"♣", F_bGREEN);
    protectedSetCursor = false;
  }
  if (y - 1 != 2) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y - 1); ColourCout (u8"♣", F_bGREEN);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y - 1); ColourCout (u8"♣", F_bGREEN);
    protectedSetCursor = false;
  }
  if (y + 1 != 18) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y + 1); ColourCout (u8"♣", F_bGREEN);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y + 1); ColourCout (u8"♣", F_bGREEN);
    protectedSetCursor = false;
  }
}
void Area::yellow (COORD position) {
  int y = position.Y;
  int x = position.X;
  if (x - 1 != 2) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y - 1); ColourCout (u8"♣", F_YELLOW);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y + 1); ColourCout (u8"♣", F_YELLOW);
    protectedSetCursor = false;
  }
  if (x + 1 != 88) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y + 1); ColourCout (u8"♣", F_YELLOW);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y - 1); ColourCout (u8"♣", F_YELLOW);
    protectedSetCursor = false;
  }
  if (y - 1 != 2) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y - 1); ColourCout (u8"♣", F_YELLOW);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y - 1); ColourCout (u8"♣", F_YELLOW);
    protectedSetCursor = false;
  }
  if (y + 1 != 18) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y + 1); ColourCout (u8"♣", F_YELLOW);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y + 1); ColourCout (u8"♣", F_YELLOW);
    protectedSetCursor = false;
  }
}
void Area::red (COORD position) {
  int y = position.Y;
  int x = position.X;
  if (x - 1 != 2) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y - 1); ColourCout (u8"♣", F_RED);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y + 1); ColourCout (u8"♣", F_RED);
    protectedSetCursor = false;
  }
  if (x + 1 != 88) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y + 1); ColourCout (u8"♣", F_RED);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y - 1); ColourCout (u8"♣", F_RED);
    protectedSetCursor = false;
  }
  if (y - 1 != 2) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y - 1); ColourCout (u8"♣", F_RED);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y - 1); ColourCout (u8"♣", F_RED);
    protectedSetCursor = false;
  }
  if (y + 1 != 18) {
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x - 1, y + 1); ColourCout (u8"♣", F_RED);
    protectedSetCursor = false;
    do {} while (protectedSetCursor == true);
    protectedSetCursor = true;
    gotoXY (x + 1, y + 1); ColourCout (u8"♣", F_RED);
    protectedSetCursor = false;
  }
}

void Area::fullPacked () {

}