// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,01.04.2019</changed>
// ********************************************************************************

#include "pch.h"


Inserter::Inserter ()
{};


COORD Inserter::currentPosition { 0,0 };
HANDLE Inserter::consoleOutput { GetStdHandle ( STD_OUTPUT_HANDLE ) };
CONSOLE_SCREEN_BUFFER_INFOEX Inserter::screenBinfoEX {};


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


void Inserter::colourInserter ( const std::string& str, const WORD& colour, const COORD& pos )
{
  currentPosition = pos;
  GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  SetConsoleCursorPosition ( consoleOutput, pos );
  SetConsoleTextAttribute ( consoleOutput, colour );
  std::cout << str;
};