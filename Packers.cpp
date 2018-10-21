// Packers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include "pch.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"
#include "Packer.h"


unsigned char menu[] { 1,1,1 };
bool flag = false;


int main () {
  // font
  COORD fontS { 10,20 };
  ConsoleFont_SizeColour (fontS, L"Consolas", 0x0d);
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


  Area area1 (1);

  gotoXY (7, 0);
  std::cout << u8"Feel free to way in as a packer toward becoming an advanced packer ♥♥♥♥♥ :)";

  gotoXY (3, 20); ColourCout (u8"Packing speed:", 0x0f);
  gotoXY (3, 21); ColourCout (u8"  Stone age.", 0x0f);
  gotoXY (2, 21); ColourCout (u8"->", 0x0c);
  gotoXY (3, 22); ColourCout (u8"  Middle age...", 0x0f);
  gotoXY (3, 23); ColourCout (u8"  Advanced age.........", 0x0f);
  gotoXY (3, 24); ColourCout (u8"  Hollow age.         .", 0x0f);
  gotoXY (35, 20); ColourCout (u8"Character Choices:", 0x0f);
  gotoXY (35, 21); ColourCout (u8"  ☺  ", 0x07);
  gotoXY (40, 21); ColourCout (u8"    ☻", 0x0f);
  gotoXY (40, 21); ColourCout (u8"->", 0x0c);
  gotoXY (65, 21); ColourCout (u8"  Involve me!", 0x0f);
  gotoXY (64, 21); ColourCout (u8"->", 0x0c);
  gotoXY (65, 22); ColourCout (u8"  Let me furnish! :)", 0x0f);
  gotoXY (65, 23); ColourCout (u8"  Let's hit the road!", 0x0f);


  // guide bar
  gotoXY (6, 27); ColourCout (u8"♣:", 0x02); ColourCout (u8" a healthy resource", 0x09);
  gotoXY (38, 27); ColourCout (u8"☻:", 0x0f); ColourCout (u8" a beloved packer", 0x09);
  gotoXY (68, 27); ColourCout (u8"▪", 0x0f); ColourCout (u8" already packed!", 0x09);


  loading ();


  Packer Packer1 (100);
  Packer Packer2 (101);
  Packer Packer3 (102);
  Packer Packer4 (103);
  Packer Packer5 (104);
  Packer Packer6 (105);
  Packer Packer7 (106);
  Packer Packer8 (107);
  //Packer Packer9 (108);
  //Packer Packer10 (109);
  //Packer Packer11 (110);
  //Packer Packer12 (111);
  //Packer Packer13 (112);
  //Packer Packer14 (113);
  //Packer Packer15 (114);
  //Packer Packer16 (115);

  std::list<Packer> allPackersList;
  std::list<Packer> packerGroupA;
  std::list<Packer> packerGroupB;
  std::list<Packer> packerGroupC;
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


  // status bar
  //add: already in age
  gotoXY (91, 3); ColourCout (u8"☻:", 0x0f); ColourCout (" " + std::to_string (allPackersList.size ()), 0x09);
  gotoXY (91, 4); ColourCout (u8"▪:", 0x0f); ColourCout (" ", 0x09);
  gotoXY (91, 5); ColourCout (u8"♣:", 0x0f); ColourCout (" ", 0x09);
  gotoXY (91, 7); ColourCout (u8"package state:", 0x0f);
  gotoXY (91, 8); ColourCout (u8"used ", 0x0f); ColourCout (" ", 0x09);
  gotoXY (91, 9); ColourCout (u8"need ", 0x0f); ColourCout (" ", 0x09);
  gotoXY (91, 10); ColourCout (u8"ready ", 0x0f); ColourCout (" ", 0x09);


  while (allPackersList.size () != 0) {
    if (allPackersList.front ().state == 1000)
      packerGroupA.insert (packerGroupA.begin (), allPackersList.front ());
    else
      if (allPackersList.front ().state == 2000)
        packerGroupB.insert (packerGroupB.begin (), allPackersList.front ());
      else
        if (allPackersList.front ().state == 3000)
          packerGroupC.insert (packerGroupC.begin (), allPackersList.front ());
    allPackersList.pop_front ();
  }


  std::thread t1 (Packer::hQuickMovement, packerGroupA, 3);
  std::thread t2 (Packer::hNormalMovement, packerGroupB, 2);
  std::thread t3 (Packer::hSlowMovement, packerGroupC, 1);

  // coding for action area
  while (running) {
    system ("pause>nul");

    std::thread t5 (pressed, menu, flag);

    t5.join ();
  }

  //t4.join ();
  t3.join ();
  t2.join ();
  t1.join ();

  SetConsoleOutputCP (consoleOutputCPstorage); // important: always set codec back to what it was
}