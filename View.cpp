
// ===========================================================================
/// <summary>
/// View.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 09.06.2022
/// </summary>
/// <created>ʆϒʅ, 09.06.2022</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================


#include "Packers.h"
#include "View.h"


View::View ()
{

    try
    {

#ifdef _WIN32
        viewConsoleInput = nullptr;
        viewConsoleOutput = nullptr;

        consoleInMode = 0;
        consoleOutMode = 0;

        BOOL result;
        viewConsoleInput = GetStdHandle (STD_INPUT_HANDLE);
        if (viewConsoleInput != INVALID_HANDLE_VALUE)
        {
            result = GetConsoleMode (viewConsoleInput, &consoleInMode);

            if (result == true)
            {
                viewConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);

                if (viewConsoleOutput != INVALID_HANDLE_VALUE)
                {
                    result = GetConsoleMode (viewConsoleOutput, &consoleOutMode);

                    if (result == true)
                    {
                        initialized = true;
                    } else
                    {
                        initialized = false;
                        return;
                    }

                } else
                {
                    initialized = false;
                    return;
                }
            } else
            {
                initialized = false;
                return;
            }
        } else
        {
            initialized = false;
            return;
        }


        DWORD modeOutput = consoleOutMode | (ENABLE_VIRTUAL_TERMINAL_INPUT | DISABLE_NEWLINE_AUTO_RETURN);
        DWORD modeInput = consoleInMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;

        // if (SetConsoleMode (viewConsoleInput, modeInput)) {
        //     if (SetConsoleMode (viewConsoleOutput, modeOutput)) {
        //         initialized = true;
        //     } else {
        //         modeOutput = ENABLE_VIRTUAL_TERMINAL_PROCESSING | consoleOutMode;
        //         if (SetConsoleMode (viewConsoleOutput, modeOutput)) {
        //             initialized = true;
        //         } else {
        //             initialized = false;
        //             return;
        //         }
        //     }
        // } else {
        //     initialized = false;
        //     return;
        // }

        consoleScreenInfo = {};
        consoleScreenInfoEx = {};
        consoleFontInfo = {};
        consoleCursorInfo = {};
#else ifdef __APPLE__
#endif // _WIN32

        setView (0, false);

    } catch (const std::exception& err)
    {
        initialized = false;
    }

};


void View::setScreen (short width, short height, short left, short top)
{

#ifdef _WIN32
    BOOL result {0};
    DWORD errorCode {0x0};
    LPCVOID errorMsg {};


    result = SetWindowPos (viewConsoleWindow, HWND_TOP,
                           left, top, width * 13,
                           height * 20, SWP_SHOWWINDOW);

    result = GetConsoleScreenBufferInfoEx (viewConsoleOutput, &consoleScreenInfoEx);


    if (result)
    {

    } else
    {

        errorCode = GetLastError ();
        FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |
                       FORMAT_MESSAGE_FROM_SYSTEM |
                       FORMAT_MESSAGE_IGNORE_INSERTS, nullptr,
                       errorCode, 0, (LPTSTR) &errorMsg, 0, 0);
        //MessageBox ( 0, (LPCTSTR) errorMsg, "Error", MB_OK );

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

#else ifdef __APPLE__
    std::wcout << "\x1b[3;" << std::to_string (top) << ";" << std::to_string (left) << "t";
    std::wcout << "\x1b[8;" << std::to_string (height) << ";" << std::to_string (width) << "t";
#endif // _WIN32

};


void View::setView (unsigned int codec, bool cursor)
{

    //    aa = new caller();
        //place = *aa->place;
        //EnumSystemCodePages ( (CODEPAGE_ENUMPROC) caller::calls ( codeSystems ), CP_INSTALLED );

#ifdef _WIN32
    GetCPInfoEx (cpStorage, 0, &cpInfoEx);
    cpStorage = GetConsoleOutputCP ();
    SetConsoleOutputCP (codec);

    GetConsoleCursorInfo (viewConsoleOutput, &consoleCursorInfo);
    consoleCursorInfo.bVisible = cursor;
    consoleCursorInfo.dwSize = POINTER_DEVICE_TYPE_INTEGRATED_PEN;
    SetConsoleCursorInfo (viewConsoleOutput, &consoleCursorInfo);
#else ifdef __APPLE__
#endif // _WIN32

};


#ifdef _WIN32
void View::setFont (std::wstring fontName, unsigned char fontX, unsigned char fontY, unsigned short colour)
#else ifdef __APPLE__
void View::setFont (std::wstring fontName, unsigned char fontX, unsigned char fontY, std::wstring colour)
#endif // _WIN32
{

#ifdef _WIN32
    BOOL result {0};
    DWORD errorCode {0x0};
    LPCVOID errorMsg {};

    result = GetCurrentConsoleFontEx (viewConsoleOutput, FALSE, &consoleFontInfo);


    if (1)
    {

        consoleFontInfo.cbSize = sizeof (consoleFontInfo);
        consoleFontInfo.dwFontSize = COORD {fontX, fontY};

        for (unsigned char i = 0; i <= fontName.size (); i++)
        {
            consoleFontInfo.FaceName [i] = fontName [i];
            //b.pop_back ();
        }

        consoleFontInfo.FontWeight = 100;

        result = SetCurrentConsoleFontEx (viewConsoleOutput, FALSE, &consoleFontInfo);


        if (result)
        {
            result = SetConsoleTextAttribute (viewConsoleOutput, colour);
        }


    } else
    {

        CONSOLE_FONT_INFO a {};
        result = GetCurrentConsoleFont (viewConsoleOutput, FALSE, &a);
        COORD t {};
        t = GetConsoleFontSize (viewConsoleOutput, a.nFont);

        errorCode = GetLastError ();
        FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |
                       FORMAT_MESSAGE_FROM_SYSTEM |
                       FORMAT_MESSAGE_IGNORE_INSERTS, nullptr,
                       errorCode, 0, (LPTSTR) &errorMsg, 0, 0);
        //MessageBox ( 0, (LPCTSTR) errorMsg, "Error", MB_OK );

    }

#else ifdef __APPLE__
    std::wcout << E_cursorOFF;
#endif // _WIN32

};


#ifdef _WIN32
CODEPAGE_ENUMPROC CALLBACK View::calledProc (LPWSTR codedObj)
{
    if (codedObj)
    {
        //
    }
    //CODEPAGE_ENUMPROCW a { codedObj };
    //typedef BOOL (
    //CK* CODEPAGE_ENUMPROCW)(LPWSTR);
    return (CODEPAGE_ENUMPROC) true;

};


const HANDLE* View::getConsoleInput ()
{
    return &viewConsoleInput;

};


const HANDLE* View::getConsoleOutput ()
{
    return &viewConsoleOutput;

};

const HWND* View::getConsoleWindow ()
{
    return &viewConsoleWindow;

};


#else ifdef __APPLE__
#endif // _WIN32


const bool& View::isInitialized ()
{

    return initialized;

};


void View::release ()
{

#ifdef _WIN32
    SetConsoleOutputCP (cpStorage);
    // if (SetConsoleMode (viewConsoleOutput, consoleOutMode)) {
    //     if (SetConsoleMode (viewConsoleOutput, consoleInMode)) {
    //         initialized = false;
    //         initialized = false;
    //     } else {
    //         // throw or log
    //     }
    // }
#else ifdef __APPLE__
#endif // _WIN32

};
