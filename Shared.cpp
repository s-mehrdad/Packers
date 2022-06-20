// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.10.2018</created>
/// <changed>ʆϒʅ,20.06.2022</changed>
// ********************************************************************************

#include "Packers.h"
#include "Shared.h"


Inserter::Inserter ()
{
    insertConsoleOutput = getConsoleOutput ();
    //screenBinfoEX = {};
};


void Inserter::colourInserter ( const coordinateType& pos )
{
    lastInsertStartPosition = pos;
    SetConsoleCursorPosition ( *insertConsoleOutput, COORD { pos.x,pos.y } );
};


void Inserter::colourInserter ( const std::string& str, const WORD& colour )
{
    SetConsoleTextAttribute ( *insertConsoleOutput, colour );
    std::cout << str;
};


void Inserter::colourInserter ( const std::string& str, const coordinateType& pos )
{
    lastInsertStartPosition = pos;
    SetConsoleCursorPosition ( *insertConsoleOutput, COORD { pos.x,pos.y } );

    std::cout << str;
};


void Inserter::colourInserter ( const std::string& str, const WORD& colour, const coordinateType& pos )
{
    lastInsertStartPosition = pos;
    SetConsoleCursorPosition ( *insertConsoleOutput, COORD { pos.x,pos.y } );
    SetConsoleTextAttribute ( *insertConsoleOutput, colour );

    std::cout << str;
};


void Inserter::clear ()
{
    coordinateType temp { 0,0 };
    coordinateType zero { 0,0 };
    std::string strTemp { u8"" };
    for ( unsigned char i = 0; i <= SCREEN_W; i += 10 )
    {
        strTemp += u8"           ";
    }
    for ( unsigned char i = 0; i <= SCREEN_H; i++ )
    {
        colourInserter ( strTemp, temp );
        temp.y++;
    }
    //for ( unsigned char i = 0; i <= SCREEN_H + ( SCREEN_H / 3 ); i++ )
    //    std::cout << strTemp;
    colourInserter ( zero );
}
coordinateType Inserter::lastInsertStartPosition { 0,0 };


Loading::Loading ( const unsigned char& mode )
{
    // set
    std::string str { u8"LOADING# " };
    unsigned char i { 0 };
    for ( char element : str )
    {
        characters [i] = element;
        ++i;
    }
    copywrite = u8"  ©: ʆϒʅ"; // usable in true type fonts
    copywrite = u8"  ©: }Y{";
    colourOne = B_bBLUE | F_bWHITE;
    colourTwo = B_BLACK | F_bGREEN;
    colourThree = B_BLACK | F_bWHITE;
    startPoint = { SCREEN_W - 13, SCREEN_H - 3 };
    speed = mode;

    // cout
    inserter ();
    //std::thread tOne ( inserter );
    //tOne.join ();
};


void Loading::inserter ()
{
    coordinateType position { startPoint };
    for ( unsigned char i = 0; i < 7; i++ )
    {
        colourInserter ( characters [i], colourOne, position );
        std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 * speed ) );
        position.x += 1;
    }
    for ( unsigned char i = 1; i <= 3; i++ )
    {
        colourInserter ( characters [7], colourTwo, position );
        std::this_thread::sleep_for ( std::chrono::milliseconds ( 150 * speed ) );
        colourInserter ( characters [8], colourTwo, position );
        std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 * speed ) );
    }
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 * speed ) );
    colourInserter ( copywrite, colourThree, startPoint );
};


void Loading::setter ( const unsigned char& mode )
{
    speed = mode;
    inserter ();
};
