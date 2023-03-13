
// ********************************************************************************
/// <summary>
/// Input.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 18.06.2022
/// </summary>
/// <created>ʆϒʅ, 18.06.2022</created>
/// <changed>ʆϒʅ, 13.03.2023</changed>
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
        // studied references: man pages
        // open source crossplatform terminals at:
        // https://github.com/martinRenou/terminal
        // https://github.com/jupyter-xeus/cpp-terminal
        //        temp.c_cflag;
        //        temp.c_iflag;
        //        temp.c_oflag;
        temp.c_lflag &= ~(ECHO |ICANON);
        temp.c_cc[VMIN]=0;
        temp.c_cc[VTIME]=0;
        //        temp.c_ispeed = ;
        temp.c_ospeed = B115200;
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
    pressedKey=keyboardKeys::None;
    
    char c {'1'};
    char numberOfBytes {0};
    std::string test {""};
    char chr[8] {'0'};
    int intTest {0};
    coordinateType pos {SCREEN_W-25,SCREEN_H};
    coordinateType tempPos {pos};
    //    c=getchar();
    for (int i=7; i>=0; i--) {
        if ((numberOfBytes = read(STDIN_FILENO, &c, 1)) == -1){
            //        errno;
        } else
        {
            if (numberOfBytes != 0) {
                test+=std::to_string(c)+" ";
                chr[i]=c;
                intTest+=numberOfBytes;
                if (intTest==1) {
                    tempPos.y=pos.y-8;
                    colourInserter("     ", tempPos);
                    for (int i=intTest-1; i<=9; i++) {
                        tempPos.y=pos.y-i;
                        colourInserter("                    ", tempPos);
                    }
                }
                tempPos.y=pos.y-i;
                switch (c) {
                    case 0x07:
                        colourInserter("\\a", F_CYAN, tempPos);
                        break;
                    case 0x08:
                        colourInserter("\\b", F_CYAN, tempPos);
                        break;
                    case 0x09:
                        colourInserter("\\t", F_CYAN, tempPos);
                        break;
                    case 0x0a:
                        colourInserter("\\n", F_CYAN, tempPos);
                        pressedKey = keyboardKeys::Return;
                        break;
                    case 0x0b:
                        colourInserter("\\v", F_CYAN, tempPos);
                        break;
                    case 0x0c:
                        colourInserter("\\f", F_CYAN, tempPos);
                        break;
                    case 0x0d:
                        colourInserter("\\r", F_CYAN, tempPos);
                        pressedKey = keyboardKeys::Return;
                        break;
                    case 0x1b:
                        colourInserter("\\e", F_CYAN, tempPos);
                        break;
                    case 0x7F:
                        colourInserter("\\Delete character", F_CYAN, tempPos);
                        break;
                        
                    default:
                        colourInserter(c, F_CYAN, tempPos);
                        break;
                }
            }
        };
    }
    if ((test!="")&&(intTest!=0)) {
        tempPos.y=pos.y-9;
        colourInserter(test, F_bRED, tempPos);
        tempPos.y=pos.y-8;
        colourInserter(std::to_string(intTest), F_YELLOW, {SCREEN_W-25,SCREEN_H-8});
    }
    switch (chr[7]) {
        case 0x1b:
            if (intTest==1) {
                pressedKey=keyboardKeys::Esc;
            } else
            {
                //                for (int i=6; i>=intTest; i--) {
                if (chr[5]!='0') {
                    switch (chr[5]) {
                        case 'A':
                            pressedKey=keyboardKeys::Up;
                            break;
                        case 'B':
                            pressedKey=keyboardKeys::Down;
                            break;
                        case 'C':
                            pressedKey=keyboardKeys::Right;
                            break;
                        case 'D':
                            pressedKey=keyboardKeys::Left;
                            break;
                    }
                }
            }
            
        default:
            break;
    }
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


const keyboardKeys& TheInput::getPressedKey(void)
{
    
    return pressedKey;
    
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
