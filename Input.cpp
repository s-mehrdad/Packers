// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,18.06.2022</created>
/// <changed>ʆϒʅ,20.06.2022</changed>
// ********************************************************************************

#include "Packers.h"
#include "Input.h"


TheInput::TheInput ( void )
{

    inputConsoleOutput = getConsoleOutput ();
    cmodeStoreage = 0x0;

    BOOL result { 0 };

    result = GetConsoleMode ( *inputConsoleOutput, &cmodeStoreage );

    //result = SetConsoleMode ( *inputConsoleOutput, cmodeStoreage | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT );

    if ( result )
    {



    } else
    {

        //error

    }

};


void TheInput::inputProcessInput ( void )
{

    INPUT_RECORD inputBufferArray [128] { 0 };
    DWORD inputBufferRead { 0 };

    WINDOWINFO consoleWindow;
    consoleWindow.cbSize = sizeof ( WINDOWINFO );

    BOOL result { 0 };
    result = GetWindowInfo ( *getConsoleWindow (), &consoleWindow );
    //result = ReadConsoleInputW ( *getConsoleOutput (), inputBufferArray, 128, &inputBufferRead );

    if ( consoleWindow.dwWindowStatus == WS_ACTIVECAPTION )
    {
        //runningOne = false;
    }

    if ( !inputBufferRead )
    {
        inputBufferRead = 128;
    }

    if ( inputBufferRead )
    {


        for ( DWORD i = 0; i < inputBufferRead; i++ )
        {
            switch ( inputBufferArray [i].EventType )
            {
            case KEY_EVENT:
                processKeyboard ();
                break;
            case MOUSE_EVENT:
                processMouse ();
                break;
            case WINDOW_BUFFER_SIZE_EVENT:
                processViewResize ();
                break;
            case FOCUS_EVENT: // windows APIs internal events
            case MENU_EVENT:
            default:
                break;
            }
        }
    } else
    {
        //process error
    }

};


void TheInput::processKeyboard ()
{



};


void TheInput::processMouse ()
{

};


void TheInput::processViewResize ()
{

};


void TheInput::release ( void )
{

    SetConsoleMode ( *inputConsoleOutput, cmodeStoreage );

};
