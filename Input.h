
// ********************************************************************************
/// <summary>
/// Input.h
/// Packers
/// created by Mehrdad Soleimanimajd on 18.06.2022
/// </summary>
/// <created>ʆϒʅ, 18.06.2022</created>
/// <changed>ʆϒʅ, 09.03.2023</changed>
// ********************************************************************************

#ifndef INPUT_H
#define INPUT_H


#include "View.h"


class TheInput : public View, Inserter
{
private:
#ifdef _WIN32
    const HANDLE* inputConsoleOutput;
    DWORD cmodeStoreage;
#elifdef __APPLE__
    struct termios orig_termios;
#endif
    bool process;
    
    void processKeyboard();
    void processMouse();
    void processViewResize();
public:
    TheInput();
    void processInput();
    const bool& getProcess(void);
    void release(void);
};


#endif // !INPUT_H
