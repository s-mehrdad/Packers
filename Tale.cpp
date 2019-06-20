// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.04.2019</created>
/// <changed>ʆϒʅ,20.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
//#include "Area.h"
//#include "Infobars.h"
//#include "Menus.h"
//#include "Packer.h"
//#include "Status.h"
//#include "Surround.h"
#include "Tale.h"
#include "Shared.h"
#include "Console.h"


//TODO to be added: funny literature of the game! :)
struct Tale::storyLine
{

} _storyLine;


struct Tale::creatures
{
  WORD colourOne { F_bWHITE };
  WORD colourTwo { F_bBLUE };
  WORD colourThree { F_RED };
  WORD colourFour { F_YELLOW };
  COORD startPointGiant { 3, SCREEN_H - 35 };
  COORD startPointSentence { 50, SCREEN_H - 40 };
  COORD startPointNarratorSentences { SCREEN_W - 60, SCREEN_H - 10 };
  std::string title { u8"A giant:" };
  std::string sentenceOne [8] { u8"\"Look",u8"at",u8"these",u8"new",u8"puny",u8"two",u8"legs",u8"creatures!\"" };
  std::string sentenceTwo [7] { u8"\"Look",u8"how",u8"they",u8"dance",u8"and",u8"chew",u8"away!\"" };
  std::string narratorSentences [3] {
    u8"It is not sure, what the giant sees up there!",
    u8"Supercomputer still dates on load process of stone age!",
    u8"So the next scene is foreseen to let us wait a little!" };
  void inserter ()
  {
    COORD tempOne ( startPointGiant );
    COORD tempTwo ( tempOne );
    colourInserter ( u8"                      ;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"                     ;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"                     ;;■;;■;;", colourOne, tempOne );
    tempTwo.Y = tempOne.Y;
    tempTwo.X = tempOne.X + 23;
    colourInserter ( u8"■", colourTwo, tempTwo );
    tempTwo.X = tempOne.X + 26;
    colourInserter ( u8"■", colourTwo, tempTwo );
    tempOne.Y += 1;
    colourInserter ( u8"                     ;;;▌▐;;;", colourOne, tempOne );
    tempTwo.Y = tempOne.Y;
    tempTwo.X = tempOne.X + 24;
    colourInserter ( u8"▌▐", colourTwo, tempTwo );
    tempOne.Y += 1;
    colourInserter ( u8"                     ;;▄▄▄▄;;", colourOne, tempOne );
    tempTwo.Y = tempOne.Y;
    tempTwo.X = tempOne.X + 23;
    colourInserter ( u8"▄▄▄▄", colourTwo, tempTwo );
    tempOne.Y += 1;
    colourInserter ( u8"                      ;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"                 ;;;;;;;;;;;;;;;                  ;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"                 ;;;;;;;;;;;;;;;;          ;;  ;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"                ;;;;;;;;;;;;;;;;;;        ;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8";;             ;;;;;;;;;;;;♥;;;;;;;       ;;;;", colourOne, tempOne );
    tempTwo.Y = tempOne.Y;
    tempTwo.X = tempOne.X + 27;
    colourInserter ( u8"♥", colourThree, tempTwo );
    tempOne.Y += 1;
    colourInserter ( u8" ;;           ;;;;;;;;;;;;;;;;;;;;;;    ;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"  ;;         ;;;; ;;;;;;;;;;;;;; ;;;;; ;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"  ;;        ;;;;  ;;;;;;;;;;;;;;   ;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;      ;;;;   ;;;;;;;;;;;;;;     ;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;     ;;;;    ;;;;;;;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;    ;;;;      ;;;;;;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;  ;;;;        ;;;;;;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"  ;;; ;;;;         ;;;;;;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"  ;;;;;;           ;;;;;;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"  ;;;;              ;;;;;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;               ;;;;;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;               ;;;;; ;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;               ;;;;;  ;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;               ;;;;;  ;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;               ;;;;;; ;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;                ;;;;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;                 ;;;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;                    ;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;                     ;;;;;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;                     ;;;;; ;;;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;                     ;;;;   ;;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;                    ;;;;;  ;;;;", colourOne, tempOne );
    tempOne.Y += 1;
    colourInserter ( u8"   ;;                   ;;;;;  ;;;;", colourOne, tempOne );

    COORD tempThree ( startPointSentence );
    colourInserter ( title, colourTwo, startPointSentence );
    tempThree.Y += 2;
    for ( unsigned char i = 0; i <= 7; i++ )
    {
      colourInserter ( sentenceOne [i], colourOne, tempThree );
      tempThree.X += static_cast<short> ( sentenceOne [i].length () + 1 );
      std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 ) );
    }
    tempThree = startPointSentence;
    tempThree.Y += 3;
    for ( unsigned char i = 0; i <= 6; i++ )
    {
      colourInserter ( sentenceTwo [i], colourOne, tempThree );
      tempThree.X += static_cast<short> ( sentenceTwo [i].length () + 1 );
      std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 ) );
    }
    for ( unsigned char i = 0; i < 3; i++ )
    {
      colourInserter ( narratorSentences [i], colourFour, startPointNarratorSentences );
      startPointNarratorSentences.Y += 1;
    }
  };
} _creatures;


Tale::Tale ( unsigned char mode )
{
  // set

  // cout
  //_storyLine.inserter ();
  _creatures.inserter ();
};


void Tale::newSetter ( void )
{
  //TODO add: new setter
  //TODO add: new couter
};
