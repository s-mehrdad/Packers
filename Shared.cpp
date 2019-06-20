// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.10.2018</created>
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
//#include "Tale.h"
#include "Shared.h"
#include "Console.h"


#pragma region temp
HANDLE consoleOutput2 { GetStdHandle ( STD_OUTPUT_HANDLE ) };
CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX2 {};
void colourInserter ( const COORD& pos )
{
  //currentPosition = pos;
  SetConsoleCursorPosition ( consoleOutput2, pos );
};
void colourInserter ( const std::string& str, const WORD& colour )
{
  GetConsoleScreenBufferInfoEx ( consoleOutput2, &screenBinfoEX2 );
  SetConsoleTextAttribute ( consoleOutput2, colour );
  std::cout << str;
};
void colourInserter ( const std::string& str, const COORD& pos )
{
  //currentPosition = pos;
  GetConsoleScreenBufferInfoEx ( consoleOutput2, &screenBinfoEX2 );
  SetConsoleCursorPosition ( consoleOutput2, pos );
  std::cout << str;
};
void colourInserter ( const std::string& str, const WORD& colour, const COORD& pos )
{
  //currentPosition = pos;
  GetConsoleScreenBufferInfoEx ( consoleOutput2, &screenBinfoEX2 );
  SetConsoleCursorPosition ( consoleOutput2, pos );
  SetConsoleTextAttribute ( consoleOutput2, colour );
  std::cout << str;
};
#pragma endregion


#pragma region Inserter_class
Inserter::Inserter ()
{
  consoleOutput = GetStdHandle ( STD_OUTPUT_HANDLE );
  screenBinfoEX = {};
};
void Inserter::colourInserter ( const COORD& pos )
{
  currentPosition = pos;
  SetConsoleCursorPosition ( consoleOutput, pos );
};
void Inserter::colourInserter ( const std::string& str, const WORD& colour )
{
  GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  SetConsoleTextAttribute ( consoleOutput, colour );
  std::cout << str;
};
void Inserter::colourInserter ( const std::string& str, const COORD& pos )
{
  currentPosition = pos;
  GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  SetConsoleCursorPosition ( consoleOutput, pos );
  std::cout << str;
};
void Inserter::colourInserter ( const std::string& str, const WORD& colour, const COORD& pos )
{
  currentPosition = pos;
  GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  SetConsoleCursorPosition ( consoleOutput, pos );
  SetConsoleTextAttribute ( consoleOutput, colour );
  std::cout << str;
};
void Inserter::clear ( const unsigned char& count )
{
  COORD temp { 0,0 };
  colourInserter ( u8"                                                                     ", temp );
  for ( unsigned char i = 0; i < count; i++ )
    std::cout << u8"                                                                     ";
}
COORD Inserter::currentPosition { 0,0 };
#pragma endregion


#pragma region Loading_class
//struct Loading::loadingBar
//{
//  std::string characters [9] { u8"L", u8"O", u8"A", u8"D", u8"I", u8"N", u8"G", u8"#", u8" " };
//  //std::string copywrite { u8"  ©: ʆϒʅ" }; // for fonts with more characters
//  std::string copywrite { u8"  ©: }Y{" };
//  WORD colourOne { B_bBLUE | F_bWHITE };
//  WORD colourTwo { B_BLACK | F_bGREEN };
//  WORD colourThree { B_BLACK | F_bWHITE };
//  COORD startPoint { SCREEN_W - 13, SCREEN_H - 3 };
//  unsigned char speed { 1 };
//  void inserter ()
//  {
//    COORD position { startPoint };
//    for ( unsigned char i = 0; i < 7; i++ )
//    {
//      Inserter::colourInserter ( characters [i], colourOne, position );
//      std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 * speed ) );
//      position.X += 1;
//    }
//    for ( unsigned char i = 1; i <= 3; i++ )
//    {
//      Inserter::colourInserter ( characters [7], colourTwo, position );
//      std::this_thread::sleep_for ( std::chrono::milliseconds ( 150 * speed ) );
//      Inserter::colourInserter ( characters [8], colourTwo, position );
//      std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 * speed ) );
//    }
//    std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 * speed ) );
//    Inserter::colourInserter ( copywrite, colourThree, startPoint );
//  }
//} _loadingBar;
Loading::Loading ( const unsigned char& mode )
{
  // set
  std::string str { "LOADING# " };
  unsigned char i { 0 };
  for ( char element : str )
  {
    characters [i] = element;
    ++i;
  }
  copywrite = u8"  ©: ʆϒʅ"; // usable in true type fonts
  copywrite = u8"  ©: }Y{";
  colourOne = B_bBLUE | F_bWHITE;
  colourTwo = B_BLACK | F_bGREEN;
  colourThree = B_BLACK | F_bWHITE;
  startPoint = { SCREEN_W - 13, SCREEN_H - 3 };
  speed = mode;

  // cout
  inserter ();
  //std::thread tOne ( inserter );
  //tOne.join ();
};
void Loading::inserter ()
{
  COORD position { startPoint };
  for ( unsigned char i = 0; i < 7; i++ )
  {
    colourInserter ( characters [i], colourOne, position );
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 * speed ) );
    position.X += 1;
  }
  for ( unsigned char i = 1; i <= 3; i++ )
  {
    colourInserter ( characters [7], colourTwo, position );
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 150 * speed ) );
    colourInserter ( characters [8], colourTwo, position );
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 * speed ) );
  }
  std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 * speed ) );
  colourInserter ( copywrite, colourThree, startPoint );
};
void Loading::setter ( const unsigned char& mode )
{
  speed = mode;
  inserter ();
};
#pragma endregion
