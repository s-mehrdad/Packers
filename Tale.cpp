// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.04.2019</created>
/// <changed>ʆϒʅ,01.04.2019</changed>
// ********************************************************************************

#include "pch.h"
#include "Tale.h"
#include "Shared.h"
#include "ConsoleAdjustments.h"
#include "Area.h"
#include "Packer.h"
#include "Surround.h"


//TODO to be added: funny literature of the game! :)
struct Tale::storyLine
{

} _storyLine;


struct Tale::creatures
{
  WORD colourOne { F_bWHITE };
  WORD colourTwo { F_bBLUE };
  WORD colourThree { F_RED };
  COORD startPointGiant { 0, SCREEN_H - 20 };
  COORD startPointSentence { 33, SCREEN_H - 25 };
  std::string title { u8"A giant:" };
  std::string sentenceOne [8] { u8"\"Look",u8"at",u8"these",u8"new",u8"puny",u8"two",u8"legs",u8"creatures!\"" };
  std::string sentenceTwo [7] { u8"\"Look",u8"how",u8"they",u8"dance",u8"and",u8"chew",u8"away!\"" };
  void inserter ()
  {
    COORD tempOne ( startPointGiant );
    COORD tempTwo ( tempOne );
    Inserter::colourInserter ( u8"                        @@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"                      @@@@@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"                    @@♦@@♦@@", colourOne, tempOne );
    tempTwo.Y = tempOne.Y;
    tempTwo.X = tempOne.X + 22;
    Inserter::colourInserter ( u8"♦", colourTwo, tempTwo );
    tempTwo.X = tempOne.X + 25;
    Inserter::colourInserter ( u8"♦", colourTwo, tempTwo );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"                     @@@@@@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"                      @@@@           @@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"                  @@@@@@@@@@@@@   @@@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"                 @@@@@@@♥@@@@@@@@@@@@", colourOne, tempOne );
    tempTwo.Y = tempOne.Y;
    tempTwo.X = tempOne.X + 24;
    Inserter::colourInserter ( u8"♥", colourThree, tempTwo );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"                @@@ @@@@@@@@   @@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"               @@@ @@@@@@@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"              @@@  @@@@@@@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"               @@  @@@@ @@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"              @@   @@@@ @@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"              @@   @@@ @@@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"              @@   @@@ @@@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"              @@  @@@  @@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"             @@  @@@  @@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"                 @@@  @@@", colourOne, tempOne );
    tempOne.Y += 1;
    Inserter::colourInserter ( u8"                 @@@  @@@", colourOne, tempOne );

    COORD tempThree ( startPointSentence );
    Inserter::colourInserter ( title, colourTwo, startPointSentence );
    tempThree.Y += 2;
    for ( unsigned char i = 0; i <= 7; i++ )
    {
      Inserter::colourInserter ( sentenceOne [i], colourOne, tempThree );
      tempThree.X += sentenceOne [i].length () + 2;
      std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 ) );
    }
    tempThree = startPointSentence;
    tempThree.Y += 3;
    for ( unsigned char i = 0; i <= 6; i++ )
    {
      Inserter::colourInserter ( sentenceTwo [i], colourOne, tempThree );
      tempThree.X += sentenceTwo [i].length () + 2;
      std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 ) );
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