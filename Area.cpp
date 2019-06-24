﻿// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,24.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
#include "Area.h"
//#include "Infobars.h"
//#include "Menus.h"
//#include "Packer.h"
//#include "Status.h"
//#include "Surround.h"
//#include "Tale.h"
#include "Shared.h"
#include "Console.h"


Area::Area ( unsigned char mode ) :age ( mode )
{
  wallH = u8"═"; // Unicode: "━"
  wallV = u8"║"; // Unicode: "┃"
  edges [0] = u8"╔"; // Unicode: "┏"
  edges [1] = u8"╚"; // Unicode: "┗"
  edges [2] = u8"╝"; // Unicode: "┛"
  edges [3] = u8"╗"; // Unicode: "┓"
  colourW = F_bBLUE;
  rows = SCREEN_H - 12;
  columns = SCREEN_W - 18;
  resources [0] = u8"♠";
  resources [1] = u8"♣";
  resources [2] = u8"♦";
  colourH = F_bGREEN;
  colourR = F_YELLOW;
  colourV = F_bRED;

  // area
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
          colourInserter ( edges [0], colourW );
        colourInserter ( wallH, colourW );
      }

      // right top edge
      if ( y == 1 && x == columns )
        colourInserter ( edges [3], colourW );

      // left bottom edge
      if ( y == rows && x == 1 )
        colourInserter ( edges [1], colourW );

      // second horizontal wall
      if ( y == rows && x != columns )
        colourInserter ( wallH, colourW );
      else
        // right bottom edge
        if ( y == rows && x == columns )
          colourInserter ( edges [2], colourW );
        else

          // vertical walls
          if ( x == 1 || x == columns )
            if ( y != 1 )
              colourInserter ( wallV, colourW );

      // packs
      if ( y != 1 && y != rows && y % 2 == 0 )
        if ( x != 1 && x != columns && x % 2 == 0 )
          colourInserter ( resources [1], colourH );
      std::cout << '\n';
    }
  }
};


void Area::setter ( const unsigned short& state, const COORD& position )
{
  //TODO to be added: other resource colours + reconstruction
  int wisherId { state / 100 };
  int wishedResource { ( state % 100 ) };
  wishedResource /= 10;
  int currentState { state % 10 };

  switch ( wishedResource )
  {
    case 1:
      if ( position.X - 1 != 2 )
      {
        colourInserter ( { position.X - 1, position.Y - 1 } );
        colourInserter ( u8"♣", F_YELLOW );
        //stateArray [position.Y - 1][position.X - 1] = currentState;
      } else
        if ( position.X + 1 != 88 )
        {
          colourInserter ( { position.X + 1, position.Y - 1 } );
          colourInserter ( u8"♣", F_YELLOW );
          //stateArray [position.Y - 1][position.X + 1] = currentState;
        }
      break;
    case 2:
      if ( position.Y - 1 != 2 )
      {
        colourInserter ( { position.X - 1, position.Y - 1 } );
        colourInserter ( u8"♣", F_YELLOW );
        //stateArray [position.Y - 1][position.X - 1] = currentState;
      } else
        if ( position.Y + 1 != 18 )
        {
          colourInserter ( { position.X - 1, position.Y + 1 } );
          colourInserter ( u8"♣", F_YELLOW );
          //stateArray [position.Y + 1][position.X - 1] = currentState;
        }
      break;
    case 3:
      if ( position.X - 1 != 2 )
      {
        colourInserter ( { position.X - 1, position.Y + 1 } );
        colourInserter ( u8"♣", F_YELLOW );
        //stateArray [position.Y + 1][position.X - 1] = currentState;
      } else
        if ( position.X + 1 != 88 )
        {
          colourInserter ( { position.X + 1, position.Y + 1 } );
          colourInserter ( u8"♣", F_YELLOW );
          //stateArray [position.Y + 1][position.X + 1] = currentState;
        }
      break;
    case 4:
      if ( position.Y - 1 != 2 )
      {
        colourInserter ( { position.X + 1, position.Y - 1 } );
        colourInserter ( u8"♣", F_YELLOW );
        //stateArray [position.Y - 1][position.X + 1] = currentState;
      } else
        if ( position.Y + 1 != 18 )
        {
          colourInserter ( { position.X + 1, position.Y + 1 } );
          colourInserter ( u8"♣", F_YELLOW );
          //stateArray [position.Y + 1][position.X + 1] = currentState;
        }
      break;
  }
};


const COORD& Area::get ()
{
  COORD frame { columns, rows };
  return frame;
};


//struct Area::materials
//{
//  struct walls
//  {
//    //std::string hWalls { u8"━" };
//    //std::string vWalls { u8"┃" };
//    //std::string edges [4] { u8"┏",u8"┗",u8"┛",u8"┓" };
//    std::string hWalls { u8"═" };
//    std::string vWalls { u8"║" };
//    std::string edges [4] { u8"╔",u8"╚",u8"╝",u8"╗" };
//    WORD colour { F_bBLUE };
//  } _walls;
//
//  struct resources
//  {
//    std::string pack { u8"♣" };
//    WORD colourOne { F_bGREEN };
//    WORD colourTwo { F_YELLOW };
//    WORD colourTree { F_bRED };
//    void inserter ()
//    {
//
//    }
//  } _resources;
//} _materials;
//
//
//Area::Area ( unsigned char mode ) : age ( mode )
//{
//  COORD position;
//  for ( int y = 1; y <= rows; y++ )
//  {
//    for ( int x = 1; x <= columns; x++ )
//    {
//      position.X = x;
//      position.Y = y;
//      colourInserter ( position );
//
//      // first horizontal wall
//      if ( y == 1 && x != columns )
//      {
//
//        // left top edge
//        if ( y == 1 && x == 1 )
//          colourInserter ( _materials._walls.edges [0], _materials._walls.colour );
//        colourInserter ( _materials._walls.hWalls, _materials._walls.colour );
//      }
//
//      // right top edge
//      if ( y == 1 && x == columns )
//        colourInserter ( _materials._walls.edges [3], _materials._walls.colour );
//
//      // left bottom edge
//      if ( y == rows && x == 1 )
//        colourInserter ( _materials._walls.edges [1], _materials._walls.colour );
//
//      // second horizontal wall
//      if ( y == rows && x != columns )
//        colourInserter ( _materials._walls.hWalls, _materials._walls.colour );
//      else
//        // right bottom edge
//        if ( y == rows && x == columns )
//          colourInserter ( _materials._walls.edges [2], _materials._walls.colour );
//        else
//
//          // vertical walls
//          if ( x == 1 || x == columns )
//            if ( y != 1 )
//              colourInserter ( _materials._walls.vWalls, _materials._walls.colour );
//
//      // packs
//      if ( y != 1 && y != rows && y % 2 == 0 )
//        if ( x != 1 && x != columns && x % 2 == 0 )
//          colourInserter ( _materials._resources.pack, _materials._resources.colourOne );
//      std::cout << '\n';
//    }
//  }
//};
//
//
//unsigned char Area::stateArray [rows][columns] { 1 };
//
//
//void Area::inserter ()
//{};
//
//
//void Area::resourceSetter ( unsigned short state, COORD position )
//{
//  //TODO to be added: other resource colours + reconstruction
//  int wisherId { state / 100 };
//  int wishedResource { ( state % 100 ) };
//  wishedResource /= 10;
//  int currentState { state % 10 };
//
//  switch ( wishedResource )
//  {
//    case 1:
//      if ( position.X - 1 != 2 )
//      {
//        colourInserter ( { position.X - 1, position.Y - 1 } );
//        colourInserter ( u8"♣", F_YELLOW );
//        stateArray [position.Y - 1][position.X - 1] = currentState;
//      } else
//        if ( position.X + 1 != 88 )
//        {
//          colourInserter ( { position.X + 1, position.Y - 1 } );
//          colourInserter ( u8"♣", F_YELLOW );
//          stateArray [position.Y - 1][position.X + 1] = currentState;
//        }
//      break;
//    case 2:
//      if ( position.Y - 1 != 2 )
//      {
//        colourInserter ( { position.X - 1, position.Y - 1 } );
//        colourInserter ( u8"♣", F_YELLOW );
//        stateArray [position.Y - 1][position.X - 1] = currentState;
//      } else
//        if ( position.Y + 1 != 18 )
//        {
//          colourInserter ( { position.X - 1, position.Y + 1 } );
//          colourInserter ( u8"♣", F_YELLOW );
//          stateArray [position.Y + 1][position.X - 1] = currentState;
//        }
//      break;
//    case 3:
//      if ( position.X - 1 != 2 )
//      {
//        colourInserter ( { position.X - 1, position.Y + 1 } );
//        colourInserter ( u8"♣", F_YELLOW );
//        stateArray [position.Y + 1][position.X - 1] = currentState;
//      } else
//        if ( position.X + 1 != 88 )
//        {
//          colourInserter ( { position.X + 1, position.Y + 1 } );
//          colourInserter ( u8"♣", F_YELLOW );
//          stateArray [position.Y + 1][position.X + 1] = currentState;
//        }
//      break;
//    case 4:
//      if ( position.Y - 1 != 2 )
//      {
//        colourInserter ( { position.X + 1, position.Y - 1 } );
//        colourInserter ( u8"♣", F_YELLOW );
//        stateArray [position.Y - 1][position.X + 1] = currentState;
//      } else
//        if ( position.Y + 1 != 18 )
//        {
//          colourInserter ( { position.X + 1, position.Y + 1 } );
//          colourInserter ( u8"♣", F_YELLOW );
//          stateArray [position.Y + 1][position.X + 1] = currentState;
//        }
//      break;
//  }
//
//
//}
