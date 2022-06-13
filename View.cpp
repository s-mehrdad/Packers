// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,09.06.2022</created>
/// <changed>ʆϒʅ,13.06.2022</changed>
// ********************************************************************************


#include "Packers.h"
#include "View.h"
//#include "Console.h"


View::View ()
{
  LPDWORD mode {};
  viewConsoleOutput = GetStdHandle ( STD_OUTPUT_HANDLE );
  //BOOL result = GetConsoleMode ( viewConsoleOutput, mode );
  viewConsoleWindow = GetConsoleWindow ();

  consoleScreenInfo = {};
  consoleScreenInfoEx = {};
  consoleFontInfo = {};
  consoleCursorInfo = {};

  setView ( 0, false );
};


void View::setScreen ( short width, short height, short left, short top )
{

  BOOL result { 0 };
  DWORD errorCode { 0x0 };
  LPCVOID errorMsg {};


  result = GetConsoleScreenBufferInfoEx ( viewConsoleOutput, &consoleScreenInfoEx );

  result = SetWindowPos ( viewConsoleWindow, HWND_TOP,
                          left, top, width * 9.3,
                          height * 22, SWP_NOMOVE | SWP_NOSIZE );

  //result = MoveWindow ( viewConsoleWindow, left, top, width * 9.3, height * 22, true );

  if (result)
  {



  } else
  {

    errorCode = GetLastError ();
    FormatMessage ( FORMAT_MESSAGE_ALLOCATE_BUFFER |
                    FORMAT_MESSAGE_FROM_SYSTEM |
                    FORMAT_MESSAGE_IGNORE_INSERTS, nullptr,
                    errorCode, 0, (LPTSTR) &errorMsg, 0, 0 );
    //MessageBox ( 0, (LPCTSTR) errorMsg, L"Error", MB_OK );

  }


  SMALL_RECT rect {};
  rect.Left = left;
  rect.Top = top;
  rect.Bottom = height * 22;
  rect.Right = width * 9.3;


  consoleScreenInfoEx.bFullscreenSupported = false;
  //consoleScreenInfoEx.cbSize = sizeof ( consoleScreenInfoEx );

  //consoleScreenInfoEx.ColorTable [0] = { 0x006368C2 };
  //consoleScreenInfoEx.ColorTable [0] = RGB ( 99, 104, 194 );
  //for (char i = 1; i < 16; i++)
  //{
  //  consoleScreenInfoEx.ColorTable [i] = { 0x00000000 };
  //}
  consoleScreenInfoEx.dwCursorPosition = COORD { 0, 0 };
  consoleScreenInfoEx.dwMaximumWindowSize = COORD { width, height };
  consoleScreenInfoEx.dwSize = COORD { width, height };
  consoleScreenInfoEx.srWindow = rect;
  consoleScreenInfoEx.wAttributes = B_bGREEN;

  result = SetConsoleScreenBufferInfoEx ( viewConsoleOutput, &consoleScreenInfoEx );

  result = SetConsoleWindowInfo ( viewConsoleOutput, true, &rect );


};


void View::setView ( unsigned int codec, bool cursor )
{
  aa = new caller ();
  //place = *aa->place;
  //EnumSystemCodePages ( (CODEPAGE_ENUMPROC) caller::calls ( codeSystems ), CP_INSTALLED );


  GetCPInfoEx ( cpStorage, 0, &cpInfoStorage );
  cpStorage = GetConsoleOutputCP ();
  SetConsoleOutputCP ( codec );

  GetConsoleCursorInfo ( viewConsoleOutput, &consoleCursorInfo );
  consoleCursorInfo.bVisible = cursor;
  consoleCursorInfo.dwSize = POINTER_DEVICE_TYPE_INTEGRATED_PEN;
  SetConsoleCursorInfo ( viewConsoleOutput, &consoleCursorInfo );

};


void View::setFont ( std::wstring fontName, unsigned char fontX, unsigned char fontY, unsigned short colour )
{

  BOOL result { 0 };
  DWORD errorCode { 0x0 };
  LPCVOID errorMsg {};

  result = GetCurrentConsoleFontEx ( viewConsoleOutput, FALSE, &consoleFontInfo );


  if (1)
  {

    consoleFontInfo.cbSize = sizeof ( consoleFontInfo );
    consoleFontInfo.dwFontSize = COORD { 0, fontY };

    for (unsigned char i = 0; i < 9; i++)
    {
      consoleFontInfo.FaceName [i] = fontName [i];
      //b.pop_back ();
    }

    consoleFontInfo.FontWeight = 100;

    result = SetCurrentConsoleFontEx ( viewConsoleOutput, FALSE, &consoleFontInfo );


    if (result)
    {
      result = SetConsoleTextAttribute ( viewConsoleOutput, colour );
    }


  } else
  {

    CONSOLE_FONT_INFO a {};
    result = GetCurrentConsoleFont ( viewConsoleOutput, FALSE, &a );
    COORD t {};
    t = GetConsoleFontSize ( viewConsoleOutput, a.nFont );

    errorCode = GetLastError ();
    FormatMessage ( FORMAT_MESSAGE_ALLOCATE_BUFFER |
                    FORMAT_MESSAGE_FROM_SYSTEM |
                    FORMAT_MESSAGE_IGNORE_INSERTS, nullptr,
                    errorCode, 0, (LPTSTR) &errorMsg, 0, 0 );
    //MessageBox ( 0, (LPCTSTR) errorMsg, L"Error", MB_OK );

  }


};


CODEPAGE_ENUMPROC CALLBACK View::calledProc ( LPWSTR codedObj )
{
  if (codedObj)
  {
    //
  }
  //CODEPAGE_ENUMPROCW a { codedObj };
  //typedef BOOL (CALLBACK* CODEPAGE_ENUMPROCW)(LPWSTR);
  return (CODEPAGE_ENUMPROC) true;
};


const HANDLE* View::getConsoleOutput ()
{
  return &viewConsoleOutput;
};


const HWND* View::getConsoleWindow ()
{
  return &viewConsoleWindow;
};


void View::release ()
{

  SetConsoleOutputCP ( cpStorage );


};
