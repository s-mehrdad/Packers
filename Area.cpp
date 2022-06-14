// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,14.06.2022</changed>
// ********************************************************************************

#include "Packers.h"
#include "Area.h"


Area::Area ( unsigned char mode, std::string name ) :
  age ( mode ),
  GameElement::GameElement ( 0, "", 0, { 0,0 }, 0, "" )
{

  setGetElementId () = 1;
  setGetElementName () = name;
  setGetsceneNumber () = 2;
  setGetElementStartPoint () = { 1,1 };
  setGetElementRow () = { 1 };
  setGetElementName () = "left";


  wallH = u8"═"; // Unicode: "━"
  wallV = u8"║"; // Unicode: "┃"
  edges [0] = u8"╔"; // Unicode: "┏"
  edges [1] = u8"╚"; // Unicode: "┗"
  edges [2] = u8"╝"; // Unicode: "┛"
  edges [3] = u8"╗"; // Unicode: "┓"
  colourW = F_CYAN;
  rows = SCREEN_H - 12;
  columns = SCREEN_W - 18;
  resources [0] = u8"♠";
  resources [1] = u8"♣";
  resources [2] = u8"♦";
  colourH = F_GREEN;
  colourR = F_YELLOW;
  colourV = F_bRED;

};


void Area::draw ()
{

  // area
  coordinateType position;
  for (int y = 1; y <= rows; y++)
  {
    for (int x = 1; x <= columns; x++)
    {
      position.x = x;
      position.y = y;
      colourInserter ( position );

      // first horizontal wall
      if (y == 1 && x != columns)
      {

        // left top edge
        if (y == 1 && x == 1)
          colourInserter ( edges [0], colourW );
        colourInserter ( wallH, colourW );
      }

      // right top edge
      if (y == 1 && x == columns)
        colourInserter ( edges [3], colourW );

      // left bottom edge
      if (y == rows && x == 1)
        colourInserter ( edges [1], colourW );

      // second horizontal wall
      if (y == rows && x != columns)
        colourInserter ( wallH, colourW );
      else
        // right bottom edge
        if (y == rows && x == columns)
          colourInserter ( edges [2], colourW );
        else

          // vertical walls
          if (x == 1 || x == columns)
            if (y != 1)
              colourInserter ( wallV, colourW );

      // packs
      if (y != 1 && y != rows && y % 2 == 0)
        if (x != 1 && x != columns && x % 2 == 0)
          colourInserter ( resources [1], colourH );
      std::cout << '\n';
    }
  }
};


void Area::setter ( const unsigned short& state, const coordinateType& position )
{
  //TODO to be added: other resource colours + reconstruction
  int wish { state };
  wish /= 10;

  switch (wish)
  {
    case 1:
      if (position.x - 1 > 2)
      {
        coordinateType temp { position.x - 1, position.y - 1 };
        colourInserter ( temp );
        colourInserter ( u8"♣", F_YELLOW );
        //stateArray [position.y - 1][position.x - 1] = currentState;
      } else
        if (position.x + 1 < columns)
        {
          coordinateType temp { position.x + 1, position.y - 1 };
          colourInserter ( temp );
          colourInserter ( u8"♣", F_YELLOW );
          //stateArray [position.y - 1][position.x + 1] = currentState;
        }
      break;
    case 2:
      if (position.y - 1 > 2)
      {
        coordinateType temp { position.x - 1, position.y - 1 };
        colourInserter ( temp );
        colourInserter ( u8"♣", F_YELLOW );
        //stateArray [position.y - 1][position.x - 1] = currentState;
      } else
        if (position.y + 1 < rows)
        {
          coordinateType temp { position.x - 1, position.y + 1 };
          colourInserter ( temp );
          colourInserter ( u8"♣", F_YELLOW );
          //stateArray [position.y + 1][position.x - 1] = currentState;
        }
      break;
    case 3:
      if (position.x - 1 > 2)
      {
        coordinateType temp { position.x - 1, position.y + 1 };
        colourInserter ( temp );
        colourInserter ( u8"♣", F_YELLOW );
        //stateArray [position.y + 1][position.x - 1] = currentState;
      } else
        if (position.x + 1 < columns)
        {
          coordinateType temp { position.x + 1, position.y + 1 };
          colourInserter ( temp );
          colourInserter ( u8"♣", F_YELLOW );
          //stateArray [position.y + 1][position.x + 1] = currentState;
        }
      break;
    case 4:
      if (position.y - 1 > 2)
      {
        coordinateType temp { position.x + 1, position.y - 1 };
        colourInserter ( temp );
        colourInserter ( u8"♣", F_YELLOW );
        //stateArray [position.y - 1][position.x + 1] = currentState;
      } else
        if (position.y + 1 < rows)
        {
          coordinateType temp { position.x + 1, position.y + 1 };
          colourInserter ( temp );
          colourInserter ( u8"♣", F_YELLOW );
          //stateArray [position.y + 1][position.x + 1] = currentState;
        }
      break;
  }
};


const coordinateType Area::getDimension ( void )
{
  coordinateType frame { columns, rows };
  return frame;
};
