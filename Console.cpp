// ********************************************************************************
/// <summary>
/// the searched and confronted ways for manipulation of Windows's console screen by the code itself in runtime.
/// </summary>
/// <created>ʆϒʅ,02.10.2018</created>
/// <changed>ʆϒʅ,11.06.2022</changed>
// ********************************************************************************

#include "Packers.h"
#include "Console.h"


// console screen properties
HANDLE consoleOutput = GetStdHandle ( STD_OUTPUT_HANDLE ); // for simplification
CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX;
CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEXstorage;
CONSOLE_FONT_INFOEX fontInfoEX;
CONSOLE_CURSOR_INFO cursorInfo;
HWND consoleWindow = GetConsoleWindow (); // for simplification


void ConsoleFont ( const LPCWSTR& fontName )
{
  fontInfoEX.cbSize = sizeof ( fontInfoEX ); // getting the right size (important for many structures in the windows API)
  GetCurrentConsoleFontEx ( consoleOutput, false, &fontInfoEX );
  lstrcpyW ( fontInfoEX.FaceName, fontName ); // copies a specific number of characters from a source string to a buffer
  // in this case the properties of the wished font to the suitable field
  SetCurrentConsoleFontEx ( consoleOutput, false, &fontInfoEX );
}


void ConsoleFontSize ( const coordinateType& fontSize )
{
  fontInfoEX.cbSize = sizeof ( fontInfoEX ); // getting the right size (important for many structures in the windows API)
  GetCurrentConsoleFontEx ( consoleOutput, false, &fontInfoEX );
  fontInfoEX.dwFontSize.X = fontSize.x; // for not true type fonts
  fontInfoEX.dwFontSize.Y = fontSize.y; // Y is enough for the size of true type fonts
  SetCurrentConsoleFontEx ( consoleOutput, false, &fontInfoEX );
}


void ConsoleFontColour ( const WORD& fontColour )
{
  SetConsoleTextAttribute ( consoleOutput, fontColour );
}


void ConsoleScreenPosition ( const coordinateType& screenPosition )
{
  // draw the window from the coordinateTypeinate argument
  // and ignore the new width, height in pixels (cx, cy) i.e. (0, 0) by setting the SWP_NOSIZE flag
  // for other flags check MSDN
  SetWindowPos ( consoleWindow, HWND_TOP, screenPosition.y, screenPosition.y, 0, 0, SWP_NOSIZE );
}


void ConsoleScreenSize ( const coordinateType& ColRowCount )
{
  // setting the new console screen size in pixels:
  // converting needed columns and rows numbers to needed screen size in pixel (the numbers are reckoned by trying different numbers)
  RECT consoleScreen;
  GetWindowRect ( consoleWindow, &consoleScreen );
  MoveWindow ( consoleWindow, consoleScreen.top, consoleScreen.left, static_cast<int> (ColRowCount.x * 9.3), ColRowCount.y * 22, true );
  screenBinfoEX.cbSize = sizeof ( screenBinfoEX ); // getting the right size (important for many structures in the windows API)
  GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  screenBinfoEX.srWindow.Left = 0; // width 0 to
  screenBinfoEX.srWindow.Right = ColRowCount.x; // the number of columns (doesn't work: need legacy console tick)
  screenBinfoEX.srWindow.Top = 0; // height 0 to
  screenBinfoEX.srWindow.Bottom = ColRowCount.y; // the number of rows
  SetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  SetConsoleWindowInfo ( consoleOutput, false, &screenBinfoEX.srWindow );
}


void ConsoleScreenColour ( const COLORREF& BGcolour )
{
  screenBinfoEX.cbSize = sizeof ( screenBinfoEX ); // getting the right size (important for many structures in the windows API)
  GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  //screenBinfoEX.srWindow.Left = 0; // width 0 to
  //screenBinfoEX.srWindow.Right = ColRowCount.x; // the number of columns (doesn't work: need legacy console tick)
  //screenBinfoEX.srWindow.Top = 0; // height 0 to
  //screenBinfoEX.srWindow.Bottom = ColRowCount.y; // the number of rows
  screenBinfoEX.ColorTable [0] = BGcolour; // background colour
  SetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  SetConsoleWindowInfo ( consoleOutput, false, &screenBinfoEX.srWindow );
}


void ConsoleCursorState ( const bool& CursorVisible )
{
  GetConsoleCursorInfo ( consoleOutput, &cursorInfo );
  cursorInfo.bVisible = CursorVisible;
  //cursorInfo.dwSize = _int;
  SetConsoleCursorInfo ( consoleOutput, &cursorInfo );
}


void ColourCouter ( const std::string& strCharacter, const WORD& Colour )
{
  GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
  screenBinfoEXstorage = screenBinfoEX;
  SetConsoleTextAttribute ( consoleOutput, Colour );
  std::cout << strCharacter;
  SetConsoleTextAttribute ( consoleOutput, screenBinfoEXstorage.wAttributes );
  GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
}
