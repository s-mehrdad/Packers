

#include "pch.h"
#include "Shared.h"
#include "ConsoleAdjustments.h"
#include "Area.h"
#include "Packer.h"


bool running { true };
bool protectedSetCursor { false };


void loading (void) {
  int y { 19 };
  for (int x = 40; x <= 54; x++) {
    gotoXY (x, y); ColourCout (u8" ", 0x3f);
    std::this_thread::sleep_for (std::chrono::milliseconds (50));
  }
  gotoXY (44, y); ColourCout (u8"L", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));
  gotoXY (45, y); ColourCout (u8"O", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));
  gotoXY (46, y); ColourCout (u8"A", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));
  gotoXY (47, y); ColourCout (u8"D", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));
  gotoXY (48, y); ColourCout (u8"I", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));
  gotoXY (49, y); ColourCout (u8"N", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));
  gotoXY (50, y); ColourCout (u8"G", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (500));
  gotoXY (48, y); ColourCout (u8" ", 0x3f);
  gotoXY (49, y); ColourCout (u8" ", 0x3f);
  gotoXY (50, y); ColourCout (u8" ", 0x3f);
  gotoXY (54, y); ColourCout (u8"━", F_PINK);
  std::this_thread::sleep_for (std::chrono::milliseconds (100));
  gotoXY (48, y); ColourCout (u8"E", 0x3f);
  gotoXY (49, y); ColourCout (u8"D", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (500));
  for (int x = 53; x >= 40; x--) {
    gotoXY (x, y); ColourCout (u8"━", F_PINK);
    std::this_thread::sleep_for (std::chrono::milliseconds (50));
  }
}


void pressed (unsigned char menu[], bool flag) {
  if (GetAsyncKeyState (VK_DOWN)) {
    if (menu[0] == 1 && flag == false) {
      do {} while (protectedSetCursor == true);
      gotoXY (64, 21); ColourCout (u8"  ", F_bRED);
      do {} while (protectedSetCursor == true);
      gotoXY (64, 22); ColourCout (u8"->", F_bRED);
      menu[0] = 2;
      flag = true;
    }
    if (menu[0] == 2 && flag == false) {
      do {} while (protectedSetCursor == true);
      gotoXY (64, 22); ColourCout (u8"  ", F_bRED);
      do {} while (protectedSetCursor == true);
      gotoXY (64, 23); ColourCout (u8"->", F_bRED);
      menu[0] = 3;
      flag = true;
      //break;
    }
    flag = false;
  }
  if (GetAsyncKeyState (VK_UP)) {
    if (menu[0] == 2 && flag == false) {
      do {} while (protectedSetCursor == true);
      gotoXY (64, 21); ColourCout (u8"->", F_bRED);
      do {} while (protectedSetCursor == true);
      gotoXY (64, 22); ColourCout (u8"  ", F_bRED);
      menu[0] = 1;
      flag = true;
    }
    if (menu[0] == 3 && flag == false) {
      do {} while (protectedSetCursor == true);
      gotoXY (64, 22); ColourCout (u8"->", F_bRED);
      do {} while (protectedSetCursor == true);
      gotoXY (64, 23); ColourCout (u8"  ", F_bRED);
      menu[0] = 2;
      flag = true;
    }
    flag = false;
  }
  if (GetAsyncKeyState (VK_LEFT)) {

  }
  if (GetAsyncKeyState (VK_RIGHT)) {

  }
  if (GetAsyncKeyState (VK_RETURN)) {
    if (menu[0] == 1 && flag == false) {
      do {} while (protectedSetCursor == true);
      gotoXY (64, 21); ColourCout (u8"-> Involve me!", F_RED);
    }
  }
}