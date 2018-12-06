// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,30.11.2018</changed>
// ********************************************************************************

#include "pch.h"
#include "Area.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Packer.h"
#include "Surround.h"


struct Area::materials
{
    struct walls
    {
        std::string hWalls { u8"━" };
        std::string vWalls { u8"┃" };
        std::string edges [4] { u8"┏",u8"┗",u8"┛",u8"┓" };
        WORD colour { F_bPURPLE };
    } _walls;

    struct resources
    {
        std::string pack { u8"♣" };
        unsigned char state [rows] [columns] { 100 };
        WORD colourOne { F_bGREEN };
        WORD colourTwo { F_YELLOW };
        WORD colourTree { F_bRED };
        void inserter ()
        {

        }
    } _resources;
} _materials;


Area::Area ( unsigned char mode ) : age ( mode )
{

    COORD position;
    for ( int y = 1; y <= rows; y++ )
    {
        for ( int x = 1; x <= columns; x++ )
        {
            position.X = x;
            position.Y = y;
            colourInserter ( position );

            // first horizontal wall
            if ( y == 1 && x != columns )
            {

                // left top edge
                if ( y == 1 && x == 1 )
                    colourInserter ( _materials._walls.edges [0], _materials._walls.colour );
                colourInserter ( _materials._walls.hWalls, _materials._walls.colour );
            }

            // right top edge
            if ( y == 1 && x == columns )
                colourInserter ( _materials._walls.edges [3], _materials._walls.colour );

            // left bottom edge
            if ( y == rows && x == 1 )
                colourInserter ( _materials._walls.edges [1], _materials._walls.colour );

            // second horizontal wall
            if ( y == rows && x != columns )
                colourInserter ( _materials._walls.hWalls, _materials._walls.colour );
            else
                // right bottom edge
                if ( y == rows && x == columns )
                    colourInserter ( _materials._walls.edges [2], _materials._walls.colour );
                else

                    // vertical walls
                    if ( x == 1 || x == columns )
                        if ( y != 1 )
                            colourInserter ( _materials._walls.vWalls, _materials._walls.colour );

            // packs
            if ( y != 1 && y != rows && y % 2 == 0 )
                if ( x != 1 && x != columns && x % 2 == 0 )
                    colourInserter ( _materials._resources.pack, _materials._resources.colourOne );
            std::cout << '\n';
        }
    }
};


void Area::inserter ()
{};


void Area::colourInserter ( COORD pos )
{
    SetConsoleCursorPosition ( consoleOutput, pos );
};


void Area::colourInserter ( std::string str, WORD colour )
{
    GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
    SetConsoleTextAttribute ( consoleOutput, colour );
    std::cout << str;
};


void Area::resourceSetter ( unsigned char state, COORD position )
{
    if ( position.X - 1 != 2 )
    {
        colourInserter ( { position.X - 1, position.Y - 1 } ); colourInserter ( u8"♣", F_bGREEN );
        colourInserter ( { position.X - 1, position.Y + 1 } ); colourInserter ( u8"♣", F_bGREEN );
    }
    if ( position.X + 1 != 88 )
    {
        colourInserter ( { position.X + 1, position.Y + 1 } ); colourInserter ( u8"♣", F_bGREEN );
        colourInserter ( { position.X + 1, position.Y - 1 } ); colourInserter ( u8"♣", F_bGREEN );
    }
    if ( position.Y - 1 != 2 )
    {
        colourInserter ( { position.X - 1, position.Y - 1 } ); colourInserter ( u8"♣", F_bGREEN );
        colourInserter ( { position.X + 1, position.Y - 1 } ); colourInserter ( u8"♣", F_bGREEN );
    }
    if ( position.Y + 1 != 18 )
    {
        colourInserter ( { position.X - 1, position.Y + 1 } ); colourInserter ( u8"♣", F_bGREEN );
        colourInserter ( { position.X + 1, position.Y + 1 } ); colourInserter ( u8"♣", F_bGREEN );
    }
}