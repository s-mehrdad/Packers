
// ===========================================================================
/// <summary>
/// Input.h
/// Packers
/// created by Mehrdad Soleimanimajd on 18.06.2022
/// </summary>
/// <created>ʆϒʅ, 18.06.2022</created>
/// <changed>ʆϒʅ, 19.08.2023</changed>
// ===========================================================================

#ifndef INPUT_H
#define INPUT_H


#include "View.h"


//#ifdef _WIN32
// not defined in windows console header
//#pragma comment (lib, "kernel32.lib")

//extern "C" int __cdecl ReadConsoleInputInfoExA (HANDLE, PINPUT_RECORD, DWORD, LPDWORD, USHORT);
//#ifndef CONSOLE_READ_NOREMOVE
//#define CONSOLE_READ_NOREMOVE       0x0001
//#endif // !CONSOLE_READ_NOREMOVE
//#ifndef CONSOLE_READ_NOWAIT
//#define CONSOLE_READ_NOWAIT         0x0002
//#endif // !CONSOLE_READ_NOREMOVE
//BOOL WINAPI ReadConsoleInputExA (_In_ HANDLE hConsoleInput,
//                                 _Out_writes_ (nLenght) PINPUT_RECORD lpBuffer,
//                                 _In_ DWORD nlength,
//                                 _Out_ LPDWORD lpNumberOfEventsRead,
//                                 _In_ USHORT wFlags);
//BOOL WINAPI ReadConsoleInputExW (_In_ HANDLE hConsoleInput,
//                                 _Out_writes_ (nLenght) PINPUT_RECORD lpBuffer,
//                                 _In_ DWORD nlength,
//                                 _Out_ LPDWORD lpNumberOfEventsRead,
//                                 _In_ USHORT wFlags);
//#endif // _WIN32


enum class keyboardKeys
{
    Return, Up, Down, Left, Right, Esc, None
};


class TheInput : public View, Inserter
{
private:
#ifdef _WIN32
    DWORD currentConsoleMode;
    const HANDLE* consoleInput;
    const HANDLE* consoleOutput;

    KEY_EVENT_RECORD pressedKeyRecord;
    std::thread* readBufferRef;
    bool readBufferFlag;
    bool lockEngine;
#else ifdef __APPLE__
    struct termios orig_termios;
#endif // _WIN32

    keyboardKeys pressedKey;
    bool initialized;
    //bool process;

    void readBufferEngine (void);
    void processKeyboard (void);
    void processMouse (void);
    void processViewResize (void);
public:
    TheInput ();
    void processInput (void);
    const bool& getInitialized (void);
    const bool const getProccessedKey (keyboardKeys validateKey);
    void release (void);

#ifdef _WIN32
    using View::getConsoleInput;
    using View::getConsoleOutput;
    //using View::getConsoleWindow;
#endif // _WIN32
};


#endif // !INPUT_H
