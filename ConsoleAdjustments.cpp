

#include "pch.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Packer.h"
#include "Area.h"


// console screen properties
HANDLE consoleOutput = GetStdHandle (STD_OUTPUT_HANDLE); // for simplification (constant calls to the function)
CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX; // <windows.h>
CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEXstorage; // the same
CONSOLE_FONT_INFOEX fontInfoEX; // the same
CONSOLE_CURSOR_INFO cursorInfo; // the same
HWND consoleWindow = GetConsoleWindow (); // // for simplification (constant calls to the function)


void ConsoleFont_SizeColour (COORD fontSize, LPCWSTR fontName, WORD fontColour) {
  fontInfoEX.cbSize = sizeof (fontInfoEX); // the right size is important for many structures in the windows API
  GetCurrentConsoleFontEx (consoleOutput, false, &fontInfoEX);
  fontInfoEX.dwFontSize.X = fontSize.X; // for not true type fonts
  fontInfoEX.dwFontSize.Y = fontSize.Y; // Y is enough for the size of true type fonts
  //lstrcpyW (fontInfoEX.FaceName, L"Consolas"); // copying the properties of wished font to the suitable field
  lstrcpyW (fontInfoEX.FaceName, fontName); // copies a specific number of characters from a source string to a buffer
  SetCurrentConsoleFontEx (consoleOutput, false, &fontInfoEX);

  SetConsoleTextAttribute (consoleOutput, fontColour); // octal (first 15 hexadecimal numbers are for colours)
                                                 // numbers after the 15 are for backgrounds
                                                 // more numbers also possible which
                                                 // reminds of old systems without proper graphic driver
  //  0: black (background)  1: Blue  //  2 : Green  //  3 : Cyan  //  4 : Red  //  5 : Purple  //  6 : Yellow (Dark)  //  7 : Default white  //  8 : Gray/Grey  //  9 : Bright blue  //  10 : Bright green  //  11 : Bright cyan  //  12 : Bright red  //  13 : Pink/Magenta  //  14 : Yellow  //  15 : Bright white

}


void ConsoleScreen_SizeColourPosition (COORD screenPosition, COORD ColRowCount, COLORREF BGcolour) {
  // draw the window from the coordinate argument
  // and ignore the new width, height in pixels (cx, cy) i.e. (0, 0) by setting the SWP_NOSIZE flag
  // for other flags check MSDN
  SetWindowPos (consoleWindow, HWND_TOP, screenPosition.X, screenPosition.Y, 0, 0, SWP_NOSIZE);

  // setting the new console screen size in pixels
  // the used coordinate argument is in needed columns and rows
  RECT consoleScreen;
  GetWindowRect (consoleWindow, &consoleScreen);
  MoveWindow (consoleWindow, consoleScreen.top, consoleScreen.left, static_cast<int> (ColRowCount.X*9.3), ColRowCount.Y * 22, true);

  screenBinfoEX.cbSize = sizeof (screenBinfoEX); // the right size is important for many structures in the windows API
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  screenBinfoEX.srWindow.Left = 0; // width 0 to
  screenBinfoEX.srWindow.Right = ColRowCount.X; // the number of columns (doesn't work: need legacy console tick)
  screenBinfoEX.srWindow.Top = 0; // height 0 to
  screenBinfoEX.srWindow.Bottom = ColRowCount.Y; // the number of rows
  screenBinfoEX.ColorTable[0] = BGcolour; // background colour
  SetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  SetConsoleWindowInfo (consoleOutput, false, &screenBinfoEX.srWindow);
}


void ConsoleCursor_State (bool CursorVisible) {
  GetConsoleCursorInfo (consoleOutput, &cursorInfo);
  cursorInfo.bVisible = CursorVisible;
  //cursorInfo.dwSize = _int;
  SetConsoleCursorInfo (consoleOutput, &cursorInfo);
}


void ColourCout (std::string strCharacter, WORD Colour) {
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX); // update info
  screenBinfoEXstorage = screenBinfoEX; // store
  SetConsoleTextAttribute (consoleOutput, Colour); // changing the colour
  std::cout << strCharacter; // print
  SetConsoleTextAttribute (consoleOutput, screenBinfoEXstorage.wAttributes); // back to the past colour
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX); // update info
}


void gotoXY (int x, int y) {
  COORD Position;
  Position.X = x;
  Position.Y = y;
  protectedSetCursor = true;
  SetConsoleCursorPosition (consoleOutput, Position);
  protectedSetCursor = false;
}