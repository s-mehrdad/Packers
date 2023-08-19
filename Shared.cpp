
// ===========================================================================
/// <summary>
/// Shared.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 13.10.2018
/// </summary>
/// <created>ʆϒʅ, 13.10.2018</created>
/// <changed>ʆϒʅ, 19.08.2023</changed>
// ===========================================================================

#include "Packers.h"
#include "Shared.h"


Inserter::Inserter ()
{

#ifdef _WIN32
    consoleOutput = getConsoleOutput ();
    //screenBinfoEX = {};
#else ifdef __APPLE__
#endif // _WIN32

};


void Inserter::colourInserter (const coordinateType& pos)
{

    lastInsertStartPosition = pos;
#ifdef _WIN32
    SetConsoleCursorPosition (*consoleOutput, COORD {static_cast<short>(pos.x), static_cast<short>(pos.y)});
#else ifdef __APPLE__
    std::cout << "\x1b[" << std::to_string (pos.y) << ";" << std::to_string (pos.x) << "H";
#endif // _WIN32

};


void Inserter::colourInserter (const std::string& str, const coordinateType& pos)
{

    lastInsertStartPosition = pos;
#ifdef _WIN32
    SetConsoleCursorPosition (*consoleOutput, COORD {static_cast<short>(pos.x), static_cast<short>(pos.y)});
    std::cout << str;
#else ifdef __APPLE__
    std::cout << "\x1b[" << std::to_string (pos.y) << ";" << std::to_string (pos.x) << "H";
    std::cout << str;
#endif // _WIN32

};


#ifdef _WIN32
void Inserter::colourInserter (const std::string& str, const WORD& colour)
{

    SetConsoleTextAttribute (*consoleOutput, colour /*| B_GREEN*/);
    std::cout << str;

};


void Inserter::colourInserter (const wchar_t& chr, const WORD& colour, const coordinateType& pos)
{

    lastInsertStartPosition = pos;
    SetConsoleCursorPosition (*consoleOutput, COORD {static_cast<short>(pos.x), static_cast<short>(pos.y)});
    SetConsoleTextAttribute (*consoleOutput, colour /*| B_GREEN*/);
    std::cout << chr;

};


void Inserter::colourInserter (const std::string& str, const WORD& colour, const coordinateType& pos)
{

    lastInsertStartPosition = pos;
    SetConsoleCursorPosition (*consoleOutput, COORD {static_cast<short>(pos.x), static_cast<short>(pos.y)});
    SetConsoleTextAttribute (*consoleOutput, colour /*| B_GREEN*/);
    std::cout << str;

};


#else ifdef __APPLE__
void Inserter::colourInserter (const std::string& str, const std::string& colour)
{

    std::cout << colour;
    std::cout << str;

};


void Inserter::colourInserter (const wchar_t& chr, const std::string& colour, const coordinateType& pos)
{

    lastInsertStartPosition = pos;
    std::cout << "\x1b[" << std::to_string (pos.y) << ";" << std::to_string (pos.x) << "H";
    std::cout << colour;
    std::cout << chr;

};


void Inserter::colourInserter (const std::string& str, const std::string& colour, const coordinateType& pos)
{

    lastInsertStartPosition = pos;
    std::cout << "\x1b[" << std::to_string (pos.y) << ";" << std::to_string (pos.x) << "H";
    std::cout << colour;
    std::cout << str;

};
#endif // _WIN32


void Inserter::clear ()
{

    coordinateType temp {0,0};
    coordinateType zero {0,0};

    //#ifdef _WIN32
    std::string strTemp {""};
    //#else ifdef __APPLE__
    //    std::string strTemp {""};
    //#endif // _WIN32

    for (int i = 0; i <= SCREEN_W; i += 10)
    {
#ifdef _WIN32
        strTemp += "           ";
#else ifdef __APPLE__
        strTemp += "           ";
#endif // _WIN32
    }

    for (int i = 0; i <= SCREEN_H; i++)
    {
        //        colourInserter(strTemp, temp);
        colourInserter (strTemp, B_BLACK, temp);
        temp.y++;
    }
    //for ( int i = 0; i <= SCREEN_H + ( SCREEN_H / 3 ); i++ )
    //    std::cout << strTemp;
    colourInserter (zero);

}
coordinateType Inserter::lastInsertStartPosition {0,0};


Loading::Loading (const unsigned char& mode, coordinateType area)
{

    // set
#ifdef _WIN32
    std::string str {"LOADING# "};
#else ifdef __APPLE__
    std::string str {"LOADING# "};
#endif // _WIN32
    unsigned char i {0};
    for (int element : str)
    {
        characters [i] = element;
        ++i;
    }
#ifdef _WIN32
    copyWrite = "  ©: ʆϒʅ"; // usable in true type fonts
    copyWrite = "  ©: }Y{";
    colourOne = B_bBLUE | F_bWHITE;
    colourTwo = B_BLACK | F_bGREEN;
    colourThree = B_BLACK | F_bWHITE;
#else ifdef __APPLE__
    copyWrite = "  ©: ʆϒʅ"; // usable in true type fonts
    copyWrite = "  ©: }Y{";
    colourOne = B_bBLUE;
    colourTwo = B_BLACK;
    colourThree = B_BLACK;
#endif // _WIN32
    startPoint = {short (area.x + 6), short (area.y + 9)};
    speed = mode;

    // cout
    inserter ();
    //std::thread tOne ( inserter );
    //tOne.join ();

};


void Loading::inserter ()
{

    coordinateType position {startPoint};
    for (int i = 0; i < 7; i++)
    {
        colourInserter (characters [i], colourOne, position);
        std::this_thread::sleep_for (std::chrono::milliseconds (100 * speed));
        position.x += 1;
    }
    for (int i = 1; i <= 3; i++)
    {
        colourInserter (characters [7], colourTwo, position);
        std::this_thread::sleep_for (std::chrono::milliseconds (150 * speed));
        colourInserter (characters [8], colourTwo, position);
        std::this_thread::sleep_for (std::chrono::milliseconds (200 * speed));
    }
    std::this_thread::sleep_for (std::chrono::milliseconds (200 * speed));
    colourInserter (copyWrite, colourThree, startPoint);

};


void Loading::setter (const unsigned char& mode)
{

    speed = mode;
    inserter ();

};
