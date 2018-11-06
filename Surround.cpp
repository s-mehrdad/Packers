

#include "pch.h"
#include "Surround.h"
#include "Shared.h"
#include "ConsoleAdjustments.h"
#include "Area.h"
#include "Packer.h"


struct Surround::titelBar {
  std::string titelSentence { u8"Feel free to way in as a packer toward becoming an advanced packer ♥♥♥♥♥ :)" };
  COORD coutStartPoint { 6,27 };
} _titleBar;


struct Surround::guideBar {

  struct healthyResources {
    struct sign {
      std::string str { u8"♣:" };
      DWORD colour { F_bGREEN };
    } _sign;
    struct guide {
      std::string str { u8" healthy resources" };
      DWORD colour { F_bBLUE };
    } _guide;
    COORD coutStartPoint { 6,27 };
  } _healthyResources;

  struct belovedPackers {
    struct sign {
      std::string str { u8"☻:" };
      DWORD colour { F_bWHITE };
    } _sign;
    struct guide {
      std::string str { u8" beloved packers" };
      DWORD colour { F_bBLUE };
    } _guide;
    COORD coutStartPoint { 38,27 };
  } _belovedPackers;

  struct alreadyPacked {
    struct sign {
      std::string str { u8"▪:" };
      DWORD colour { F_bWHITE };
    } _sign;
    struct guide {
      std::string str { u8" already packed" };
      DWORD colour { F_bBLUE };
    } _guide;
    COORD coutStartPoint { 68,27 };
  } _alreadyPacked;


} _GuideBar;


struct Surround::statusBar {

  struct startState {
    struct title {
      std::string str { u8"start state>" };
      DWORD colour { F_PINK };
    } _title;
    struct packers {
      std::string str { u8"☻: " };
      DWORD colourOne { F_bWHITE };
      //add: new count in constructor
      unsigned char count { (Packer::count) };
      DWORD colourOne { F_bBLUE };
    } _packers;
    struct packages {
      std::string str { u8"▪: " };
      DWORD colourOne { F_bWHITE };
      //add: default count for the start of different ages in constructor
      unsigned int count { 0 };
      DWORD colourTwo { F_bBLUE };
    } _packages;
    struct resources {
      std::string str { u8"♣: " };
      DWORD colourOne { F_bGREEN };
      //add: default count for the start of different ages in constructor
      unsigned int count { 0 };
      DWORD colourTwo { F_bBLUE };
    } _resources;
    struct ages {
      std::string str { u8"age: " };
      DWORD colourOne { F_bWHITE };
      //add: changing in the ages
      std::string current { "Stone age" };
      DWORD colourTwo { F_bBLUE };
    } _ages;
    COORD coutStartPoint { 91,3 };
  } _startState;

  struct packageState {
    struct title {
      std::string str { u8"package state>" };
      DWORD colour { F_PINK };
    } _title;
    struct used {
      std::string str { u8"used: " };
      DWORD colourOne { F_bWHITE };
      //add: change in count
      unsigned int count { 0 };
      DWORD colourOne { F_bBLUE };
    } _used;
    struct need {
      std::string str { u8"need: " };
      DWORD colourOne { F_bWHITE };
      //add: change in count
      unsigned int count { 0 };
      DWORD colourOne { F_bBLUE };
    } _need;
    struct ready {
      std::string str { u8"ready: " };
      DWORD colourOne { F_bWHITE };
      //add: change in count
      unsigned int count { 0 };
      DWORD colourOne { F_bBLUE };
    } _ready;
    COORD coutStartPoint { 91,9 };
  } _startState;

  struct resourceState {
    struct title {
      std::string str { u8"resource state>" };
      DWORD colour { F_PINK };
    } _title;
    struct healthy {
      std::string str { u8"healthy: " };
      DWORD colourOne { F_bGREEN };
      //add: change in count
      unsigned int count { 0 };
      DWORD colourOne { F_bBLUE };
    } _healthy;
    struct renewed {
      std::string str { u8"renewed: " };
      DWORD colourOne { F_YELLOW };
      //add: change in count
      unsigned int count { 0 };
      DWORD colourOne { F_bBLUE };
    } _renewed;
    struct vanished {
      std::string str { u8"vanished: " };
      DWORD colourOne { F_RED };
      //add: change in count
      unsigned int count { 0 };
      DWORD colourOne { F_bBLUE };
    } _vanished;
    COORD coutStartPoint { 91,14 };
  } _startState;

} _statusBar;


struct Surround::menus {

  struct agesChoices {
    std::string title { u8"Packing speed:" };
    std::string options[5] {
      u8"  Stone age." ,
      u8"  Middle age..." ,
      u8"  Advanced age........." ,
      u8"  Hollow age.      . .            ." ,
      u8"  Dirty age (packers of packers contest!)" };
    DWORD colour { F_bWHITE };
    COORD coutStartPoint { 3,20 };
    struct selectionSign {
      std::string sign { u8"->" };
      DWORD colour { F_bRED };
    } sign;
  };

  struct characterChoices {
    std::string title { u8"Character Choices:" };
    std::string options[2] {
      u8"  ☺  " ,
      u8"    ☻" };
    DWORD colour { F_bWHITE };
    COORD coutStartPoint { 35,20 };
    struct selectionSign {
      std::string sign { u8"->" };
      DWORD colour { F_bRED };
    } sign;
  };

  struct dangerAreaChoices {
    std::string title { u8"  Danger area:" };
    std::string options[3] {
      u8"  Involve me!",
      u8"  Let me furnish! :)",
      u8"  Let's hit the road!" };
    DWORD colour { F_bWHITE };
    COORD coutStartPoint { 65,21 };
    struct selectionSign {
      std::string sign { u8"->" };
      DWORD colour { F_bRED };
    } sign;
  };

};