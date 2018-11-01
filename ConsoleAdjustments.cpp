

#include "pch.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Packer.h"
#include "Area.h"


HANDLE consoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX;
CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEXstorage;
CONSOLE_FONT_INFOEX fontInfoEX;
CONSOLE_CURSOR_INFO cursorInfo;
HWND consoleWindow = GetConsoleWindow ();


void ConsoleFont_SizeColour (COORD fontSize, LPCWSTR fontName, WORD fontColour) {
  fontInfoEX.cbSize = sizeof (fontInfoEX);
  GetCurrentConsoleFontEx (consoleOutput, false, &fontInfoEX);
  fontInfoEX.dwFontSize.X = fontSize.X;
  fontInfoEX.dwFontSize.Y = fontSize.Y;
  lstrcpyW (fontInfoEX.FaceName, fontName);
  SetCurrentConsoleFontEx (consoleOutput, false, &fontInfoEX);
  SetConsoleTextAttribute (consoleOutput, fontColour);
}


void ConsoleScreen_SizeColourPosition (COORD screenPosition, COORD ColRowCount, COLORREF BGcolour) {
  SetWindowPos (consoleWindow, HWND_TOP, screenPosition.X, screenPosition.Y, 0, 0, SWP_NOSIZE);
  RECT consoleScreen;
  GetWindowRect (consoleWindow, &consoleScreen);
  MoveWindow (consoleWindow, consoleScreen.top, consoleScreen.left, static_cast<int> (ColRowCount.X*9.3), ColRowCount.Y * 22, true);
  screenBinfoEX.cbSize = sizeof (screenBinfoEX);
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  screenBinfoEX.srWindow.Left = 0;
  screenBinfoEX.srWindow.Right = ColRowCount.X;
  screenBinfoEX.srWindow.Top = 0;
  screenBinfoEX.srWindow.Bottom = ColRowCount.Y;
  screenBinfoEX.ColorTable[0] = BGcolour;
  SetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  SetConsoleWindowInfo (consoleOutput, false, &screenBinfoEX.srWindow);
}


void ConsoleCursor_State (bool CursorVisible) {
  GetConsoleCursorInfo (consoleOutput, &cursorInfo);
  cursorInfo.bVisible = CursorVisible;
  SetConsoleCursorInfo (consoleOutput, &cursorInfo);
}


void ColourCout (std::string strCharacter, WORD Colour) {
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  screenBinfoEXstorage = screenBinfoEX;
  SetConsoleTextAttribute (consoleOutput, Colour);
  std::cout << strCharacter;
  SetConsoleTextAttribute (consoleOutput, screenBinfoEXstorage.wAttributes);
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
}


void gotoXY (int x, int y) {
  COORD Position;
  Position.X = x;
  Position.Y = y;
  protectedSetCursor = true;
  SetConsoleCursorPosition (consoleOutput, Position);
  protectedSetCursor = false;
}