// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,18.06.2022</created>
/// <changed>ʆϒʅ,20.06.2022</changed>
// ********************************************************************************

#ifndef INPUT_H
#define INPUT_H


#include "View.h"


class TheInput : public View
{
private:
    const HANDLE* inputConsoleOutput;
    DWORD cmodeStoreage;

    void processKeyboard ();
    void processMouse ();
    void processViewResize ();
public:
    TheInput ();
    void inputProcessInput ();
    void release ( void );
};


#endif // !INPUT_H
