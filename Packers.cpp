// Packers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include "pch.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"
#include "Packer.h"
#include "Surround.h"


unsigned char menu[] { 1,1,1 };
bool flag = false;


int main () {

  // ConsoleAdjustments.h
  // font
  COORD fontS { 10,20 };
  ConsoleFont_SizeColour (fontS, L"Consolas", F_PINK);
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
  Area areaOne (1);


  // Surround.h
  Surround surroundOne;
  gotoXY (7, 0);
  std::cout << u8"Feel free to way in as a packer toward becoming an advanced packer ♥♥♥♥♥ :)";

  gotoXY (3, 20); ColourCout (u8"Packing speed:", F_bWHITE);
  gotoXY (3, 21); ColourCout (u8"  Stone age.", F_bWHITE);
  gotoXY (2, 21); ColourCout (u8"->", F_bRED);
  gotoXY (3, 22); ColourCout (u8"  Middle age...", F_bWHITE);
  gotoXY (3, 23); ColourCout (u8"  Advanced age.........", F_bWHITE);
  gotoXY (3, 24); ColourCout (u8"  Hollow age.      . .            .", F_bWHITE);
  gotoXY (3, 25); ColourCout (u8"  Dirty age (packers of packers contest!)", F_bWHITE);
  gotoXY (35, 20); ColourCout (u8"Character Choices:", F_bWHITE);
  gotoXY (35, 21); ColourCout (u8"  ☺  ", F_bWHITE);
  gotoXY (40, 21); ColourCout (u8"    ☻", F_bWHITE);
  gotoXY (40, 21); ColourCout (u8"->", F_bRED);
  gotoXY (65, 21); ColourCout (u8"  Danger area:", F_bWHITE);
  gotoXY (65, 22); ColourCout (u8"  Involve me!", F_bWHITE);
  gotoXY (64, 22); ColourCout (u8"->", F_bRED);
  gotoXY (65, 23); ColourCout (u8"  Let me furnish! :)", F_bWHITE);
  gotoXY (65, 23); ColourCout (u8"  Let's hit the road!", F_bWHITE);


  // guide bar
  gotoXY (6, 27); ColourCout (u8"♣:", F_bGREEN); ColourCout (u8" healthy resources", F_bBLUE);
  gotoXY (38, 27); ColourCout (u8"☻:", F_bWHITE); ColourCout (u8" beloved packers", F_bBLUE);
  gotoXY (68, 27); ColourCout (u8"▪", F_bWHITE); ColourCout (u8" already packed!", F_bBLUE);


  // status bar
  //add: already in age
  gotoXY (91, 3); ColourCout (u8"start state>", F_PINK);
  gotoXY (91, 4); ColourCout (u8"☻:", F_bWHITE); ColourCout (" " + std::to_string (Packer::count), F_bBLUE);
  gotoXY (91, 5); ColourCout (u8"▪:", F_bWHITE); ColourCout (" ", F_bBLUE);
  gotoXY (91, 6); ColourCout (u8"♣:", F_bGREEN); ColourCout (" ", F_bBLUE);
  gotoXY (91, 7); ColourCout (u8"age:", F_bWHITE); ColourCout (" ", F_bBLUE);
  gotoXY (91, 9); ColourCout (u8"package state>", F_PINK);
  gotoXY (91, 10); ColourCout (u8"used: ", F_bWHITE); ColourCout (" ", F_bBLUE);
  gotoXY (91, 11); ColourCout (u8"need: ", F_bWHITE); ColourCout (" ", F_bBLUE);
  gotoXY (91, 12); ColourCout (u8"ready: ", F_bWHITE); ColourCout (" ", F_bBLUE);
  gotoXY (91, 14); ColourCout (u8"resource state>", F_PINK);
  gotoXY (91, 15); ColourCout (u8"healthy: ", F_bGREEN); ColourCout (" ", F_bBLUE);
  gotoXY (91, 17); ColourCout (u8"renewed: ", F_YELLOW); ColourCout (" ", F_bBLUE);
  gotoXY (91, 16); ColourCout (u8"vanished: ", F_RED); ColourCout (" ", F_bBLUE);


  // making the packers ready
  Packer Packer1 (1);
  Packer Packer2 (2);
  Packer Packer3 (3);
  Packer Packer4 (4);
  Packer Packer5 (5);
  Packer Packer6 (6);
  Packer Packer7 (7);
  Packer Packer8 (8);
  //Packer Packer9 (9);
  //Packer Packer10 (10);
  //Packer Packer11 (11);
  //Packer Packer12 (12);
  //Packer Packer13 (13);
  //Packer Packer14 (14);
  //Packer Packer15 (15);
  //Packer Packer16 (16);

  std::list<Packer> allPackersList;
  allPackersList.insert (allPackersList.begin (), Packer1);
  allPackersList.insert (allPackersList.begin (), Packer2);
  allPackersList.insert (allPackersList.begin (), Packer3);
  allPackersList.insert (allPackersList.begin (), Packer4);
  allPackersList.insert (allPackersList.begin (), Packer5);
  allPackersList.insert (allPackersList.begin (), Packer6);
  allPackersList.insert (allPackersList.begin (), Packer7);
  allPackersList.insert (allPackersList.begin (), Packer8);
  //allPackersList.insert (allPackersList.begin (), Packer9);
  //allPackersList.insert (allPackersList.begin (), Packer10);
  //allPackersList.insert (allPackersList.begin (), Packer11);
  //allPackersList.insert (allPackersList.begin (), Packer12);
  //allPackersList.insert (allPackersList.begin (), Packer13);
  //allPackersList.insert (allPackersList.begin (), Packer14);
  //allPackersList.insert (allPackersList.begin (), Packer15);
  //allPackersList.insert (allPackersList.begin (), Packer16);


  // loading
  std::thread t1 (loading);
  t1.join ();


  //Packer::hMovement (allPackersList);
  //std::thread t1 (&Packer::moveCout, Packer (1));
  //std::thread t2 (&Packer::moveCout, Packer (2));
  //std::thread t3 (&Packer::moveCout, Packer (3));
  //std::thread t4 (&Packer::moveCout, Packer (4));

  //std::thread tt2 (&Packer::movementCout);

  //std::thread tt3 (pressed, menu, flag);


  // coding for action area
  do {

    // pause for user decision

    if (GetAsyncKeyState (VK_RETURN)) {
      pressed (menu, flag);
    }


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

  //tt3.join ();

  //tt2.join ();
  //t4.join ();
  //t3.join ();
  //t2.join ();
  //t1.join ();


  // back to system default
  SetConsoleOutputCP (consoleOutputCPstorage);
}