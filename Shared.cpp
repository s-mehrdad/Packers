// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.10.2018</created>
/// <changed>ʆϒʅ,29.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
#include "Shared.h"
#include "Console.h"


Inserter::Inserter ()
{
  consoleOutput = GetStdHandle ( STD_OUTPUT_HANDLE );
  screenBinfoEX = {};
};
void Inserter::colourInserter ( const COORD& pos )
{
  lastInsertStartPosition = pos;
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
  lastInsertStartPosition = pos;
  GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  SetConsoleCursorPosition ( consoleOutput, pos );
  std::cout << str;
};
void Inserter::colourInserter ( const std::string& str, const WORD& colour, const COORD& pos )
{
  lastInsertStartPosition = pos;
  GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  SetConsoleCursorPosition ( consoleOutput, pos );
  SetConsoleTextAttribute ( consoleOutput, colour );
  std::cout << str;
};
void Inserter::clear ()
{
  COORD temp { 0,0 };
  std::string strTemp { "" };
  for ( unsigned char i = 0; i < SCREEN_W; i++ )
  {
    strTemp += " ";
  }
  colourInserter ( strTemp, temp );
  for ( unsigned char i = 0; i < SCREEN_H; i++ )
    std::cout << strTemp;
}
COORD Inserter::lastInsertStartPosition { 0,0 };


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
