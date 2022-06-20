// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,09.06.2022</created>
/// <changed>ʆϒʅ,20.06.2022</changed>
// ********************************************************************************

#ifndef VIEW_H
#define VIEW_H


class caller
{
public:
    CODEPAGE_ENUMPROC* CALLBACK place;
    caller ()
    {
        place = nullptr;
    };
    caller ( CODEPAGE_ENUMPROC obj )
    {
        place = &obj;
    };
    static bool calls ( LPWSTR )
    {
        return true;
    };
};


class View
{
private:
    CODEPAGE_ENUMPROC CALLBACK place;
    caller* aa;
    LPWSTR codeSystems;
    //int test_;
    HANDLE viewConsoleOutput;
    HWND viewConsoleWindow;
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenInfo;
    CONSOLE_SCREEN_BUFFER_INFOEX consoleScreenInfoEx;
    CONSOLE_FONT_INFOEX consoleFontInfo;
    CONSOLE_CURSOR_INFO consoleCursorInfo;
    UINT cpStorage;
    CPINFOEX cpInfoEx;

public:
    View (); //construct needed console window properties
    void setScreen ( short width, short height, short left, short top );
    void setView ( unsigned int codec, bool cursor );
    void setFont ( std::string fontName, unsigned char fontX, unsigned char fontY, unsigned short colour );
    static CODEPAGE_ENUMPROC CALLBACK calledProc ( LPWSTR );
    const HANDLE* getConsoleOutput ();
    const HWND* getConsoleWindow ();
    void release ();
};


#endif // !VIEW_H
