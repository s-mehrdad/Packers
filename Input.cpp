
// ********************************************************************************
/// <summary>
/// Input.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 18.06.2022
/// </summary>
/// <created>ʆϒʅ, 18.06.2022</created>
/// <changed>ʆϒʅ, 09.03.2023</changed>
// ********************************************************************************

#include "Packers.h"
#include "Input.h"


TheInput::TheInput(void)
{
    
#ifdef _WIN32
    inputConsoleOutput = getConsoleOutput();
    cmodeStoreage = 0x0;
    
    process = false;
    
    BOOL result{ 0 };
    
    result = GetConsoleMode(*inputConsoleOutput, &cmodeStoreage);
    
    //result = SetConsoleMode ( *inputConsoleOutput, cmodeStoreage | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT );
    
    if (result)
    {
        
        
        
    }
    else
    {
        
        //error
        
    }
#elifdef __APPLE__
    if(tcgetattr(STDIN_FILENO, &orig_termios) != 0){
        // error
    } else {
        termios temp {orig_termios};
        //        temp.c_iflag &= ~(BRKINT);
        temp.c_lflag &= ~(ECHO | ICANON);
        temp.c_ospeed = B115200;
        //    temp.c_lflag &= ~(ISIG); // keybindings
        temp.c_cc[VMIN]=0;
        temp.c_cc[VTIME]=0;
        if ( tcsetattr(STDIN_FILENO, TCSAFLUSH, &temp) != 0 )
            //        if ( true)
        {
            // errno
        } else
        {
            
        }
    };
#endif
    
};


void TheInput::processInput(void)
{
    
#ifdef _WIN32
    INPUT_RECORD inputBufferArray[128]{ 0 };
    DWORD inputBufferRead{ 0 };
    
    WINDOWINFO consoleWindow;
    consoleWindow.cbSize = sizeof(WINDOWINFO);
    
    BOOL result{ 0 };
    result = GetWindowInfo(*getConsoleWindow(), &consoleWindow);
    //result = ReadConsoleInputW ( *getConsoleOutput (), inputBufferArray, 128, &inputBufferRead );
    
    if (consoleWindow.dwWindowStatus == WS_ACTIVECAPTION)
    {
        process = true;
    }
    else
    {
        process = false;
    }
    
    if (!inputBufferRead)
    {
        inputBufferRead = 128;
    }
    
    if (inputBufferRead)
    {
        
        
        for (DWORD i = 0; i < inputBufferRead; i++)
        {
            switch (inputBufferArray[i].EventType)
            {
                case KEY_EVENT:
                    processKeyboard();
                    break;
                case MOUSE_EVENT:
                    processMouse();
                    break;
                case WINDOW_BUFFER_SIZE_EVENT:
                    processViewResize();
                    break;
                case FOCUS_EVENT: // windows APIs internal events
                case MENU_EVENT:
                default:
                    break;
            }
        }
    }
    else
    {
        //process error
    }
#elifdef __APPLE__
    processKeyboard();
#endif
    
};


void TheInput::processKeyboard()
{
    
    char c {'1'};
    //    c=getchar();
    if (read(STDIN_FILENO, &c, 1) ==-1){
        //        errno;
    } else
    {
        colourInserter(std::to_string(c), F_RED, {SCREEN_W-5,SCREEN_H-5});
    };
    
};


void TheInput::processMouse()
{
    
};


void TheInput::processViewResize()
{
    
};


const bool& TheInput::getProcess(void)
{
    
    return process;
    
};


void TheInput::release(void)
{
    
#ifdef _WIN32
    SetConsoleMode(*inputConsoleOutput, cmodeStoreage);
#elifdef __APPLE__
    if ( tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios) != 0 ){
        //        errno
    }
#endif
    
};
