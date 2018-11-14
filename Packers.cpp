// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,14.11.2018</changed>
// ********************************************************************************

#include "pch.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"
#include "Packer.h"
#include "Surround.h"


bool running { true };
unsigned char menusSelection { 100 };
bool MenusFlag { false };


//add: construction to surround.h
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
  gotoXY (54, y); ColourCout (u8"━", F_bPURPLE);
  std::this_thread::sleep_for (std::chrono::milliseconds (100));
  gotoXY (48, y); ColourCout (u8"E", 0x3f);
  gotoXY (49, y); ColourCout (u8"D", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (500));
  for (int x = 53; x >= 40; x--) {
    gotoXY (x, y); ColourCout (u8"━", F_bPURPLE);
    std::this_thread::sleep_for (std::chrono::milliseconds (50));
  }
}


void pressed () {
  if (GetAsyncKeyState (VK_DOWN)) {
    if (menusSelection == 100 && MenusFlag == false) {
      menusSelection = 110;
      MenusFlag = true;
      Surround::menusSetter (menusSelection, false);
    }
    else
      if (menusSelection == 110 && MenusFlag == false) {
        menusSelection = 120;
        MenusFlag = true;
        Surround::menusSetter (menusSelection, false);
      }
    MenusFlag = false;
  }
  if (GetAsyncKeyState (VK_UP)) {
    if (menusSelection == 120 && MenusFlag == false) {
      menusSelection = 110;
      MenusFlag = true;
      Surround::menusSetter (menusSelection + 1, false);
    }
    else
      if (menusSelection == 110 && MenusFlag == false) {
        menusSelection = 100;
        MenusFlag = true;
        Surround::menusSetter (menusSelection + 1, false);
      }
    MenusFlag = false;
  }
  if (GetAsyncKeyState (VK_LEFT)) {

  }
  if (GetAsyncKeyState (VK_RIGHT)) {

  }
  if (GetAsyncKeyState (VK_RETURN)) {
    if (menusSelection == 100 && MenusFlag == false)
      Surround::menusSetter (menusSelection, true);
    else
      if (menusSelection == 120 && MenusFlag == false)
        running = false;
  }
}


// -------- A needed thing needs to get its done upon itself! :)
int main () {

  // ConsoleAdjustments.h
  // font
  COORD fontS { 10,20 };
  ConsoleFont_SizeColour (fontS, L"Consolas", F_bPURPLE);
  // screen
  COORD leftANDtop { 15,15 };
  COORD widthANDheight { 107,28 };
  COLORREF backColour { RGB (50,50,50) };
  ConsoleScreen_SizeColourPosition (leftANDtop, widthANDheight, backColour);
  // codec
  UINT consoleOutputCPstorage;
  consoleOutputCPstorage = GetConsoleOutputCP (); // for later use
  SetConsoleOutputCP (CP_UTF8); // https://docs.microsoft.com/de-de/windows/desktop/Intl/code-page-identifiers
  // cursor
  ConsoleCursor_State (false);


  // Area.h
  Area areaOne (0);


  // loading
  std::thread loadingThreadOne (loading);


  // packers
#pragma region pacKers
  Packer Packer1 (1);
  Packer Packer2 (2);
  Packer Packer3 (3);
  Packer Packer4 (4);
  Packer Packer5 (5);
  Packer Packer6 (6);
  Packer Packer7 (7);
  Packer Packer8 (8);
  Packer Packer9 (9);
  Packer Packer10 (10);
  Packer Packer11 (11);
  Packer Packer12 (12);
  Packer Packer13 (13);
  Packer Packer14 (14);
  Packer Packer15 (15);
  Packer Packer16 (16);
  //Packer Packer17 (17);
  //Packer Packer18 (18);
  //Packer Packer19 (19);
  //Packer Packer20 (20);
  //Packer Packer21 (21);
  //Packer Packer22 (22);
  //Packer Packer23 (23);
  //Packer Packer24 (24);
  //Packer Packer25 (25);
  //Packer Packer26 (26);
  //Packer Packer27 (27);
  //Packer Packer28 (28);
  //Packer Packer29 (29);
  //Packer Packer30 (30);
  //Packer Packer31 (31);
  //Packer Packer32 (32);

  // packers list
  std::list<Packer> allPackersList;
  allPackersList.insert (allPackersList.begin (), Packer1);
  allPackersList.insert (allPackersList.begin (), Packer2);
  allPackersList.insert (allPackersList.begin (), Packer3);
  allPackersList.insert (allPackersList.begin (), Packer4);
  allPackersList.insert (allPackersList.begin (), Packer5);
  allPackersList.insert (allPackersList.begin (), Packer6);
  allPackersList.insert (allPackersList.begin (), Packer7);
  allPackersList.insert (allPackersList.begin (), Packer8);
  allPackersList.insert (allPackersList.begin (), Packer9);
  allPackersList.insert (allPackersList.begin (), Packer10);
  allPackersList.insert (allPackersList.begin (), Packer11);
  allPackersList.insert (allPackersList.begin (), Packer12);
  allPackersList.insert (allPackersList.begin (), Packer13);
  allPackersList.insert (allPackersList.begin (), Packer14);
  allPackersList.insert (allPackersList.begin (), Packer15);
  allPackersList.insert (allPackersList.begin (), Packer16);
  //allPackersList.insert (allPackersList.begin (), Packer17);
  //allPackersList.insert (allPackersList.begin (), Packer18);
  //allPackersList.insert (allPackersList.begin (), Packer19);
  //allPackersList.insert (allPackersList.begin (), Packer20);
  //allPackersList.insert (allPackersList.begin (), Packer21);
  //allPackersList.insert (allPackersList.begin (), Packer22);
  //allPackersList.insert (allPackersList.begin (), Packer23);
  //allPackersList.insert (allPackersList.begin (), Packer24);
  //allPackersList.insert (allPackersList.begin (), Packer25);
  //allPackersList.insert (allPackersList.begin (), Packer26);
  //allPackersList.insert (allPackersList.begin (), Packer27);
  //allPackersList.insert (allPackersList.begin (), Packer28);
  //allPackersList.insert (allPackersList.begin (), Packer29);
  //allPackersList.insert (allPackersList.begin (), Packer30);
  //allPackersList.insert (allPackersList.begin (), Packer31);
  //allPackersList.insert (allPackersList.begin (), Packer32);
#pragma endregion


  // Surround.h
  Surround surroundOne (0);
  loadingThreadOne.join ();


  // coding for action area
  do {

    //performance problem:
    //add: dos-menus-like functionality
    pressed ();

    for (int i = 0; i < Packer::count; i++) {
      GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
      SetConsoleCursorPosition (consoleOutput, allPackersList.back ().position);
      SetConsoleTextAttribute (consoleOutput, allPackersList.back ().moves[0].colour);
      std::cout << allPackersList.back ().moves[0].str;

      if (allPackersList.back ().RchanceL == true) {
        if (allPackersList.back ().position.X != 87)
          allPackersList.back ().position.X += 2;
        else
          allPackersList.back ().RchanceL = false;
      }
      else
        if (allPackersList.back ().position.X != 3)
          allPackersList.back ().position.X -= 2;
        else
          allPackersList.back ().RchanceL = true;

      allPackersList.emplace_front (allPackersList.back ());
      allPackersList.pop_back ();
    }
    std::this_thread::sleep_for (std::chrono::milliseconds (allPackersList.back ().moves[0].delay));
    for (int i = 1; i < 4; i++) {
      for (int j = 0; j < Packer::count; j++) {
        SetConsoleCursorPosition (consoleOutput, allPackersList.back ().position);
        SetConsoleTextAttribute (consoleOutput, allPackersList.back ().moves[i].colour);
        std::cout << allPackersList.back ().moves[i].str;
        allPackersList.emplace_front (allPackersList.back ());
        allPackersList.pop_back ();
      }
      std::this_thread::sleep_for (std::chrono::milliseconds (allPackersList.back ().moves[i].delay));
    }
  } while (running);


  // back to system default
  SetConsoleOutputCP (consoleOutputCPstorage);
}