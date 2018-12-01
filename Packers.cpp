// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,30.11.2018</changed>
// ********************************************************************************

#include "pch.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"
#include "Packer.h"
#include "Surround.h"


bool running { true };
unsigned char menusSelection { 000 };
bool MenusFlag { false };


// -------- A needed thing needs to get its done upon itself! :)
int main () {

  // ConsoleAdjustments.h
  // font
  ConsoleFont_SizeColour ({ FONT_SIZEa, FONT_SIZEb }, FONT_NAME, F_bPURPLE);
  // screen
  ConsoleScreen_SizeColourPosition ({ SCREEN_L,SCREEN_T }, { SCREEN_W,SCREEN_H }, BACKGROUND_COLOUR);
  // codec
  UINT consoleOutputCPstorage;
  consoleOutputCPstorage = GetConsoleOutputCP ();
  SetConsoleOutputCP (CP_UTF8);
  // cursor
  ConsoleCursor_State (false);


  // Area.h
  Area areaOne (0, SCREEN_H - 9, SCREEN_W - 18);


#pragma region pacKers
  // packers
  Packer Packer1 (1);
  Packer Packer2 (2);
  Packer Packer3 (3);
  Packer Packer4 (4);
  Packer Packer5 (5);
  Packer Packer6 (6);
  Packer Packer7 (7);
  Packer Packer8 (8);

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
#pragma endregion


  // Surround.h
  Surround surroundOne (0);


  // coding for action area
  do {

#pragma region keyPRess
    //performance problem:
    if (GetAsyncKeyState (VK_RETURN)) {
      if (menusSelection == 000) {
        Surround::menusSetter (000, false);
        menusSelection = 100;
      }
      else {
        if (menusSelection == 100 && MenusFlag == false)
          Surround::menusSetter (menusSelection, true);
        else
          if (menusSelection == 120 && MenusFlag == false)
            running = false;
      }
    }

    if (menusSelection != 000) {
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
    }
#pragma endregion


    //add: more smart pants packers
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