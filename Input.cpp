
// ===========================================================================
/// <summary>
/// Input.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 18.06.2022
/// </summary>
/// <created>ʆϒʅ, 18.06.2022</created>
/// <changed>ʆϒʅ, 19.08.2023</changed>
// ===========================================================================

#include "Packers.h"
#include "Input.h"


TheInput::TheInput (void)
{

#ifdef _WIN32
    currentConsoleMode = 0x0;
    consoleInput = getConsoleInput ();
    consoleOutput = getConsoleOutput ();

    pressedKeyRecord = {};
    readBufferRef = nullptr;
    readBufferFlag = false;
    lockEngine = false;

    pressedKey = keyboardKeys::None;
    initialized = false;
    //process = false;

    DWORD consoleMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | currentConsoleMode;

    if (GetConsoleMode (*consoleInput, &currentConsoleMode))
    {
        //if (SetConsoleMode (*consoleOutput, consoleMode))
        //{
        initialized = true;
    } else
    {
        initialized = false;
        //process = false;
    }
    //}

#else ifdef __APPLE__
    if (tcgetattr (STDIN_FILENO, &orig_termios) != 0)
    {
        // error
    } else
    {
        termios temp {orig_termios};
        // studied references: man pages
        // open source crossplatform terminals at:
        // https://github.com/martinRenou/terminal
        // https://github.com/jupyter-xeus/cpp-terminal
        //        temp.c_cflag;
        //        temp.c_iflag;
        //        temp.c_oflag;
        temp.c_lflag &= ~(ECHO | ICANON);
        temp.c_cc [VMIN] = 0;
        temp.c_cc [VTIME] = 0;
        //        temp.c_ispeed = ;
        temp.c_ospeed = B115200;
        if (tcsetattr (STDIN_FILENO, TCSAFLUSH, &temp) != 0)
            //        if ( true)
        {
            // errno
        } else
        {

        }
    };
#endif // _WIN32
    //process = true;

};


void TheInput::readBufferEngine (void)
{

#ifdef _WIN32
    lockEngine = true;

    INPUT_RECORD inputBufferArray [128] {0};
    DWORD index {0}, inputBufferReadNumber {0};

    //WINDOWINFO consoleWindow;
    //consoleWindow.cbSize = sizeof (WINDOWINFO);

    //BOOL result {0};
    //result = GetWindowInfo (*getConsoleWindow (), &consoleWindow);
    //result = ReadConsoleInputW ( *getConsoleOutput (), inputBufferArray, 128, &inputBufferRead );
    //if ( consoleWindow.dwWindowStatus==WS_ACTIVECAPTION ) {
    //  process = true;
    //} else {
    //  process = false;
    //}

    int numberOfRepeat {0};

    do
    {


        if (PeekConsoleInput (*consoleInput, inputBufferArray, 128., &inputBufferReadNumber))
        {
            index = 0;

            if (inputBufferReadNumber)
                ReadConsoleInput (*consoleInput, inputBufferArray, 128., &inputBufferReadNumber);
            for (index; index < inputBufferReadNumber; index++)
            {
                if (inputBufferArray [index].EventType == KEY_EVENT)
                {
                    pressedKeyRecord = inputBufferArray [index].Event.KeyEvent;
                    processKeyboard ();
                }
                //switch (inputBufferArray [index].EventType) {
                //    case KEY_EVENT:
                //        pressedKeyRecord = inputBufferArray [index].Event.KeyEvent;
                //        processKeyboard ();
                //        break;
                //    case MOUSE_EVENT:
                //        //processMouse ();
                //        break;
                //    case WINDOW_BUFFER_SIZE_EVENT:
                //        //processViewResize ();
                //        break;
                //    case FOCUS_EVENT: // windows APIs internal events
                //    case MENU_EVENT:
                //    default:
                //        break;
                //}
            }

        } else
        {
            //break;
        }
        numberOfRepeat += 1;

        std::this_thread::sleep_for (std::chrono::milliseconds (100));

        if (numberOfRepeat == 100)
        {
            numberOfRepeat = 0;
        }

    } while (!readBufferFlag);
#endif // _WIN32

};


void TheInput::processKeyboard (void)
{

#ifdef _WIN32

    // windows native API approach
    switch (pressedKeyRecord.wVirtualKeyCode)
    {
        case VK_RETURN:
            pressedKey = keyboardKeys::Return;
            break;
        case VK_ESCAPE:
            pressedKey = keyboardKeys::Esc;
            break;
        case VK_UP:
            pressedKey = keyboardKeys::Up;
            break;
        case VK_DOWN:
            pressedKey = keyboardKeys::Down;
            break;
        case VK_RIGHT:
            pressedKey = keyboardKeys::Right;
            break;
        case VK_LEFT:
            pressedKey = keyboardKeys::Left;
            break;
        default:
            pressedKey = keyboardKeys::None;
            break;
    }
#endif  // _WIN32

    char readCharacter {'1'};
    char numberOfBytes {0};
    int readBytes {0};
    char readSequence [8] {'0'};
    std::string readSequenceRaw {""};
    coordinateType pos {SCREEN_W - 25,SCREEN_H};
    coordinateType tempPos {pos};

    //    c=getchar();

    for (int i = 7; i >= 0; i--)
    {
#ifdef _WIN32
        // windows ANSI character approach
        //readCharacter = getchar ();
        if (readCharacter != '1')
        {
            numberOfBytes = 1;
        } else
        {
            numberOfBytes = -1;
        }
        if (numberOfBytes == -1)
        {
#else ifdef __APPLE__
        if ((numberOfBytes = read (STDIN_FILENO, &readCharacter, 1)) == -1)
        {
#endif // _WIN32

            //errno;
            return;
        } else
        {

            if (numberOfBytes != 0)
            {
                readSequenceRaw += std::to_string (readCharacter) + " ";
                readSequence [i] = readCharacter;
                readBytes += numberOfBytes;
                if (readBytes == 1)
                {
                    tempPos.y = pos.y - 8;
                    //debug
                    colourInserter ("     ", tempPos);
                    for (int i = readBytes - 1; i <= 9; i++)
                    {
                        tempPos.y = pos.y - i;
                        colourInserter ("                    ", tempPos);
                    }
                }
                tempPos.y = pos.y - i;
                switch (readCharacter)
                {
                    case 0x07:
                        colourInserter ("\\a", F_CYAN, tempPos);
                        break;
                    case 0x08:
                        colourInserter ("\\b", F_CYAN, tempPos);
                        break;
                    case 0x09:
                        colourInserter ("\\t", F_CYAN, tempPos);
                        break;
                    case 0x0a:
                        colourInserter ("\\n", F_CYAN, tempPos);
                        pressedKey = keyboardKeys::Return;
                        break;
                    case 0x0b:
                        colourInserter ("\\v", F_CYAN, tempPos);
                        break;
                    case 0x0c:
                        colourInserter ("\\f", F_CYAN, tempPos);
                        break;
                    case 0x0d:
                        colourInserter ("\\r", F_CYAN, tempPos);
                        pressedKey = keyboardKeys::Return;
                        break;
                    case 0x1b:
                        colourInserter ("\\e", F_CYAN, tempPos);
                        break;
                    case 0x7F:
                        colourInserter ("\\Delete character", F_CYAN, tempPos);
                        break;

                    default:
                        colourInserter (readCharacter, F_CYAN, tempPos);
                        break;
                }

            } else
            {
                return;
            }
        }
    }
    if ((readSequenceRaw != "") && (readBytes != 0))
    {
        tempPos.y = pos.y - 9;
        colourInserter (readSequenceRaw, F_bRED, tempPos);
        tempPos.y = pos.y - 8;
        colourInserter (std::to_string (readBytes), F_YELLOW, {SCREEN_W - 25,SCREEN_H - 8});
    }
    switch (readSequence [7])
    {
        case 0x1b:
            if (readBytes == 1)
            {
                pressedKey = keyboardKeys::Esc;
            } else
            {
                //                for (int i=6; i>=intTest; i--) {
                if (readSequence [5] != '0')
                {
                    switch (readSequence [5])
                    {
                        case 'A':
                            pressedKey = keyboardKeys::Up;
                            break;
                        case 'B':
                            pressedKey = keyboardKeys::Down;
                            break;
                        case 'C':
                            pressedKey = keyboardKeys::Right;
                            break;
                        case 'D':
                            pressedKey = keyboardKeys::Left;
                            break;
                        default:
                            break;
                    }
                }
            }

        default:
            break;
    }
    //#endif // _WIN32

};


void TheInput::processMouse (void)
{

};


void TheInput::processViewResize (void)
{

};


void TheInput::processInput (void)
{

#ifdef _WIN32

    //if (pressedKey != keyboardKeys::None) {
    //    pressedKey = keyboardKeys::None;
    //}

    if ((readBufferRef == nullptr) && !lockEngine)
    {
        readBufferRef = new (std::nothrow) std::thread (&TheInput::readBufferEngine, this);
        //std::this_thread::sleep_for (std::chrono::milliseconds (1000));
        //readBufferRef.join ();
    }

#else ifdef __APPLE__
    processKeyboard ();
#endif // !_WIN32

};


const bool& TheInput::getInitialized (void)
{

    return initialized;

};


const bool const TheInput::getProccessedKey (keyboardKeys validateKey)
{

    if (validateKey == pressedKey)
    {
        pressedKey = keyboardKeys::None;
        return true;
    } else
    {
        return false;
    }

};


void TheInput::release (void)
{

#ifdef _WIN32
    // one is one is one is life
    // if (SetConsoleMode (*consoleOutput, consoleInputMode)) {
    if (readBufferRef->joinable ())
    {
        readBufferFlag = true;
        readBufferRef->join ();
        lockEngine = false;
        consoleInput = nullptr;
        consoleOutput = nullptr;
        initialized = false;
    } else
    {
        // trow or log
    }
#else ifdef __APPLE__
    if (tcsetattr (STDIN_FILENO, TCSANOW, &orig_termios) != 0)
    {
        //        errno
    }
#endif // _WIN32

};
