
// ===========================================================================
/// <summary>
/// View.h
/// Packers
/// created by Mehrdad Soleimanimajd on 09.06.2022
/// </summary>
/// <created>ʆϒʅ, 09.06.2022</created>
/// <changed>ʆϒʅ, 19.08.2023</changed>
// ===========================================================================

#ifndef VIEW_H
#define VIEW_H


//class caller
//{
//public:
//    CODEPAGE_ENUMPROC* CALLBACK place;
//    caller ()
//    {
//        place = nullptr;
//    };
//    caller ( CODEPAGE_ENUMPROC obj )
//    {
//        place = &obj;
//    };
//    static bool calls ( LPWSTR )
//    {
//        return true;
//    };
//};


class View
{
private:
#ifdef _WIN32
    CODEPAGE_ENUMPROC CALLBACK place;
    //    caller* aa;
    LPWSTR codeSystems;
    //int test_;
    HANDLE viewConsoleInput;
    HANDLE viewConsoleOutput;
    DWORD consoleInMode;
    DWORD consoleOutMode;
    HWND viewConsoleWindow;
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenInfo;
    CONSOLE_SCREEN_BUFFER_INFOEX consoleScreenInfoEx;
    CONSOLE_FONT_INFOEX consoleFontInfo;
    CONSOLE_CURSOR_INFO consoleCursorInfo;
    UINT cpStorage;
    CPINFOEX cpInfoEx;
#else ifdef __APPLE__
#endif // _WIN32
    bool initialized;

public:
    View (); //construct needed console window properties
    void setScreen (short width, short height, short left, short top);
    void setView (unsigned int codec, bool cursor);
    const bool& isInitialized ();

#ifdef _WIN32
    void setFont (std::string fontName, unsigned char fontX, unsigned char fontY, unsigned short colour);
#else ifdef __APPLE__
    void setFont (std::string fontName, unsigned char fontX, unsigned char fontY, std::string colour);
#endif // _WIN32

#ifdef _WIN32
    static CODEPAGE_ENUMPROC CALLBACK calledProc (LPWSTR);
    const HANDLE* getConsoleInput ();
    const HANDLE* getConsoleOutput ();
    const HWND* getConsoleWindow ();
#else ifdef __APPLE__
#endif // _WIN32

    void release ();
};


#endif // !VIEW_H
