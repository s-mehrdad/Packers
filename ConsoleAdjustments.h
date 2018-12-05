// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,07.10.2018</created>
/// <changed>ʆϒʅ,13.11.2018</changed>
// ********************************************************************************

#pragma once


#ifndef CONSOLEADJUSTMENTS_H
#define CONSOLEADJUSTMENTS_H


extern HANDLE consoleOutput;
extern CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX;
extern CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEXstorage;
extern CONSOLE_FONT_INFOEX fontInfoEX;
extern CONSOLE_CURSOR_INFO cursorInfo;
extern HWND consoleWindow;


void ConsoleFont_SizeColour ( COORD, LPCWSTR, WORD );
void ConsoleScreen_SizeColourPosition ( COORD, COORD, COLORREF );
void ConsoleCursor_State ( bool );
void ColourCout ( std::string, WORD );
void gotoXY ( int, int );


#endif // !CONSOLEADJUSTMENTS_H