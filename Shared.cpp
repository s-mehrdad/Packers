
// ********************************************************************************
/// <summary>
/// Shared.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 13.10.2018
/// </summary>
/// <created>ʆϒʅ, 13.10.2018</created>
/// <changed>ʆϒʅ, 09.03.2023</changed>
// ********************************************************************************

#include "Packers.h"
#include "Shared.h"


Inserter::Inserter()
{

#ifdef _WIN32
    insertConsoleOutput = getConsoleOutput();
    //screenBinfoEX = {};
#elifdef __APPLE__
#endif

};


void Inserter::colourInserter(const coordinateType& pos)
{
    lastInsertStartPosition = pos;
#ifdef _WIN32
    SetConsoleCursorPosition(*insertConsoleOutput, COORD{ pos.x,pos.y });
#elifdef __APPLE__
    std::cout << "\x1b[" << std::to_string(pos.y) << ";" << std::to_string(pos.x) << "H";
#endif
};


#ifdef _WIN32
void Inserter::colourInserter(const std::string& str, const WORD& colour)
{
    SetConsoleTextAttribute(*insertConsoleOutput, colour);
    std::cout << str;
};
#elifdef __APPLE__
void Inserter::colourInserter(const std::string& str, const std::string& colour)
{
    std::cout << colour;
    std::cout << str;
};
#endif


void Inserter::colourInserter(const std::string& str, const coordinateType& pos)
{
    lastInsertStartPosition = pos;
#ifdef _WIN32
    SetConsoleCursorPosition(*insertConsoleOutput, COORD{ pos.x,pos.y });
    std::cout << str;
#elifdef __APPLE__
    std::cout << "\x1b[" << std::to_string(pos.y) << ";" << std::to_string(pos.x) << "H";
    std::cout << str;
#endif
};


#ifdef _WIN32
void Inserter::colourInserter(const std::string& str, const WORD& colour, const coordinateType& pos)
{
    lastInsertStartPosition = pos;
    SetConsoleCursorPosition(*insertConsoleOutput, COORD{ pos.x,pos.y });
    SetConsoleTextAttribute(*insertConsoleOutput, colour);
    std::cout << str;
};
#elifdef __APPLE__
void Inserter::colourInserter(const std::string& str, const std::string& colour, const coordinateType& pos)
{
    lastInsertStartPosition = pos;
    std::cout << "\x1b[" << std::to_string(pos.y) << ";" << std::to_string(pos.x) << "H";
    std::cout << colour;
    std::cout << str;
};
#endif


void Inserter::clear()
{
    coordinateType temp{ 0,0 };
    coordinateType zero{ 0,0 };
#ifdef _WIN32
    std::string strTemp{ "" };
#elifdef __APPLE__
    std::string strTemp{ "" };
#endif
    for (unsigned char i = 0; i <= SCREEN_W; i += 10)
    {
#ifdef _WIN32
        strTemp += "           ";
#elifdef __APPLE__
        strTemp += "           ";
#endif
    }
    for (unsigned char i = 0; i <= SCREEN_H; i++)
    {
//        colourInserter(strTemp, temp);
        colourInserter(strTemp, B_BLACK, temp);
        temp.y++;
    }
    //for ( unsigned char i = 0; i <= SCREEN_H + ( SCREEN_H / 3 ); i++ )
    //    std::cout << strTemp;
    colourInserter(zero);
}
coordinateType Inserter::lastInsertStartPosition{ 0,0 };


Loading::Loading(const unsigned char& mode, coordinateType area)
{
    // set
#ifdef _WIN32
    std::string str{ "LOADING# " };
#elifdef __APPLE__
    std::string str{ "LOADING# " };
#endif
    unsigned char i{ 0 };
    for (char element : str)
    {
        characters[i] = element;
        ++i;
    }
#ifdef _WIN32
    copywrite = "  ©: ʆϒʅ"; // usable in true type fonts
    copywrite = "  ©: }Y{";
    colourOne = B_bBLUE | F_bWHITE;
    colourTwo = B_BLACK | F_bGREEN;
    colourThree = B_BLACK | F_bWHITE;
#elifdef __APPLE__
    copywrite = "  ©: ʆϒʅ"; // usable in true type fonts
    copywrite = "  ©: }Y{";
    colourOne = B_bBLUE ;
    colourTwo = B_BLACK ;
    colourThree = B_BLACK ;
#endif
    startPoint = { short(area.x + 6), short(area.y + 9) };
    speed = mode;

    // cout
    inserter();
    //std::thread tOne ( inserter );
    //tOne.join ();
};


void Loading::inserter()
{
    coordinateType position{ startPoint };
    for (unsigned char i = 0; i < 7; i++)
    {
        colourInserter(characters[i], colourOne, position);
        std::this_thread::sleep_for(std::chrono::milliseconds(100 * speed));
        position.x += 1;
    }
    for (unsigned char i = 1; i <= 3; i++)
    {
        colourInserter(characters[7], colourTwo, position);
        std::this_thread::sleep_for(std::chrono::milliseconds(150 * speed));
        colourInserter(characters[8], colourTwo, position);
        std::this_thread::sleep_for(std::chrono::milliseconds(200 * speed));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200 * speed));
    colourInserter(copywrite, colourThree, startPoint);
};


void Loading::setter(const unsigned char& mode)
{
    speed = mode;
    inserter();
};
