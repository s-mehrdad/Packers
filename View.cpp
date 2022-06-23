// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,09.06.2022</created>
/// <changed>ʆϒʅ,23.06.2022</changed>
// ********************************************************************************


#include "Packers.h"
#include "View.h"


View::View()
{
    LPDWORD mode{};
    viewConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    //BOOL result = GetConsoleMode ( viewConsoleOutput, mode );
    viewConsoleWindow = GetConsoleWindow();

    //consoleScreenInfo = {};
    //consoleScreenInfoEx = {};
    //consoleFontInfo = {};
    //consoleCursorInfo = {};

    setView(0, false);
};


void View::setScreen(short width, short height, short left, short top)
{

    BOOL result{ 0 };
    DWORD errorCode{ 0x0 };
    LPCVOID errorMsg{};


    result = SetWindowPos(viewConsoleWindow, HWND_TOP,
        left, top, width * 13,
        height * 20, SWP_SHOWWINDOW);

    result = GetConsoleScreenBufferInfoEx(viewConsoleOutput, &consoleScreenInfoEx);


    if (result)
    {

    }
    else
    {

        errorCode = GetLastError();
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS, nullptr,
            errorCode, 0, (LPTSTR)&errorMsg, 0, 0);
        //MessageBox ( 0, (LPCTSTR) errorMsg, u8"Error", MB_OK );

    }


    //RECT rect;
    //rect.left = left;
    //rect.top = top;
    //rect.bottom = height * 22;
    //rect.right = width * 15;

    //AdjustWindowRect(&rect, WS_EX_TOPMOST, false);

    //consoleScreenInfoEx.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    //consoleScreenInfoEx.bFullscreenSupported = false;

    //consoleScreenInfoEx.ColorTable [0] = { 0x006368C2 };
    //consoleScreenInfoEx.ColorTable [0] = RGB ( 99, 104, 194 );
    //for (char i = 1; i < 16; i++)
    //{
    //  consoleScreenInfoEx.ColorTable [i] = { 0x00000000 };
    //}
    //consoleScreenInfoEx.dwCursorPosition = COORD{ 0, 0 };
    //consoleScreenInfoEx.dwMaximumWindowSize = COORD{ width, height };
    //consoleScreenInfoEx.dwSize = COORD{ width, height };
    //consoleScreenInfoEx.srWindow.Left = left;
    //consoleScreenInfoEx.srWindow.Top = top;
    //consoleScreenInfoEx.srWindow.Bottom = height * 20;
    //consoleScreenInfoEx.srWindow.Right = width * 5;
    //consoleScreenInfoEx.wAttributes = B_bGREEN;

    //result = SetConsoleScreenBufferInfoEx(viewConsoleOutput, &consoleScreenInfoEx);

    //result = SetConsoleWindowInfo ( viewConsoleOutput, true, &rect );

    //result = MoveWindow ( viewConsoleWindow, left, top, width * 5, height * 10, true );

};


void View::setView(unsigned int codec, bool cursor)
{
    aa = new caller();
    //place = *aa->place;
    //EnumSystemCodePages ( (CODEPAGE_ENUMPROC) caller::calls ( codeSystems ), CP_INSTALLED );


    GetCPInfoEx(cpStorage, 0, &cpInfoEx);
    cpStorage = GetConsoleOutputCP();
    SetConsoleOutputCP(codec);

    GetConsoleCursorInfo(viewConsoleOutput, &consoleCursorInfo);
    consoleCursorInfo.bVisible = cursor;
    consoleCursorInfo.dwSize = POINTER_DEVICE_TYPE_INTEGRATED_PEN;
    SetConsoleCursorInfo(viewConsoleOutput, &consoleCursorInfo);

};


void View::setFont(std::string fontName, unsigned char fontX, unsigned char fontY, unsigned short colour)
{

    BOOL result{ 0 };
    DWORD errorCode{ 0x0 };
    LPCVOID errorMsg{};

    result = GetCurrentConsoleFontEx(viewConsoleOutput, FALSE, &consoleFontInfo);


    if (1)
    {

        consoleFontInfo.cbSize = sizeof(consoleFontInfo);
        consoleFontInfo.dwFontSize = COORD{ fontX, fontY };

        for (unsigned char i = 0; i <= fontName.size(); i++)
        {
            consoleFontInfo.FaceName[i] = fontName[i];
            //b.pop_back ();
        }

        consoleFontInfo.FontWeight = 100;

        result = SetCurrentConsoleFontEx(viewConsoleOutput, FALSE, &consoleFontInfo);


        if (result)
        {
            result = SetConsoleTextAttribute(viewConsoleOutput, colour);
        }


    }
    else
    {

        CONSOLE_FONT_INFO a{};
        result = GetCurrentConsoleFont(viewConsoleOutput, FALSE, &a);
        COORD t{};
        t = GetConsoleFontSize(viewConsoleOutput, a.nFont);

        errorCode = GetLastError();
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS, nullptr,
            errorCode, 0, (LPTSTR)&errorMsg, 0, 0);
        //MessageBox ( 0, (LPCTSTR) errorMsg, u8"Error", MB_OK );

    }


};


CODEPAGE_ENUMPROC CALLBACK View::calledProc(LPWSTR codedObj)
{
    if (codedObj)
    {
        //
    }
    //CODEPAGE_ENUMPROCW a { codedObj };
    //typedef BOOL (CALLBACK* CODEPAGE_ENUMPROCW)(LPWSTR);
    return (CODEPAGE_ENUMPROC)true;
};


const HANDLE* View::getConsoleOutput()
{
    return &viewConsoleOutput;
};


const HWND* View::getConsoleWindow()
{
    return &viewConsoleWindow;
};


void View::release()
{

    SetConsoleOutputCP(cpStorage);

};
