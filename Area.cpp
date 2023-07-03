
// ===========================================================================
/// <summary>
/// Area.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 29.09.2018
/// </summary>
/// <created>ʆϒʅ, 29.09.2018</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================

#include "Packers.h"
#include "Area.h"


TheArea::TheArea (unsigned char age, std::wstring name) :currentAge (age),
GameElement::GameElement ()
{

    setBase ();

    elementID = 0;
    elementName = name;

    firstInScene = 2;

    horizontalWall = L"═"; // notUnicode: "?"
    verticalWall = L"║"; // notUnicode: "?"
    edges [0] = L"╔"; // notUnicode: "?"
    edges [1] = L"╚"; // notUnicode: "?"
    edges [2] = L"╝"; // notUnicode: "?"
    edges [3] = L"╗"; // notUnicode: "?"

    wallColour = F_CYAN;
    rows = SCREEN_H - 10;
    columns = SCREEN_W - 0;
    if (columns % 2 == 0)
        columns -= 1;
    if (rows % 2 == 0)
        rows -= 1;

    startPoints [0] = {1, 1};
    startPoints [1] = {columns, rows};

    resources [0] = L"♠";
    resources [1] = L"♣";
    resources [2] = L"♦";
    healthyColour = F_GREEN;
    renewedColour = F_YELLOW;
    vanishedColour = F_bRED;

    inRow = 2;
    floatedTo = L"left";

};


void TheArea::setBase (void)
{

    setGetElementId () = &elementID;
    setGetElementName () = &elementName;
    setGetsceneNumber () = &firstInScene;
    setGetElementStartPoint () = startPoints;
    setGetElementRow () = &inRow;
    setGetElementFloat () = &floatedTo;

};


void TheArea::draw ()
{

    // area
    coordinateType position;
    //setGetElementStartPoint () = &position;
    int x {0};
    int y {0};
    for (y = startPoints [0].y; y <= rows; y++)
    {
        for (x = startPoints [0].x; x <= columns; x++)
        {
            position.x = x;
            position.y = y;
            colourInserter (position);

            // first horizontal wall
            if (y == startPoints [0].y && x != columns)
            {
                // left top edge
                if (y == startPoints [0].y && x == startPoints [0].x)
                    colourInserter (edges [0], wallColour);
                colourInserter (horizontalWall, wallColour);
            } else
            {
                y = 1;
            }

            // right top edge
            if (y == startPoints [0].y && x == columns)
                colourInserter (edges [3], wallColour);

            // left bottom edge
            if (y == rows && x == startPoints [0].x)
                colourInserter (edges [1], wallColour);

            // second horizontal wall
            if (y == rows && x != columns)
                colourInserter (horizontalWall, wallColour);
            else
                // right bottom edge
                if (y == rows && x == columns)
                    colourInserter (edges [2], wallColour);
                else

                    // vertical walls
                    if (x == startPoints [0].x || x == columns)
                        if (y != startPoints [0].y)
                            colourInserter (verticalWall, wallColour);

            // packs
            if (y != startPoints [0].y && y != rows && y % 2 == 0)
                if (x != startPoints [0].x && x != columns && x % 2 == 0)
                    colourInserter (resources [1], healthyColour);
            std::wcout << '\n';
        }
    }

};


void TheArea::setter (const unsigned short& state, const coordinateType& position)
{

    // TODO to be added: other resource colours + reconstruction
    int wish {state};
    wish /= 10;

    switch (wish)
    {
        case 1:
            if (position.x - 1 > 2)
            {
                coordinateType temp {position.x - 1, position.y - 1};
                colourInserter (temp);
                colourInserter (L"?", F_YELLOW);
                //stateArray [position.y - 1][position.x - 1] = currentState;
            } else
                if (position.x + 1 < columns)
                {
                    coordinateType temp {position.x + 1, position.y - 1};
                    colourInserter (temp);
                    colourInserter (L"?", F_YELLOW);
                    //stateArray [position.y - 1][position.x + 1] = currentState;
                }
            break;
        case 2:
            if (position.y - 1 > 2)
            {
                coordinateType temp {position.x - 1, position.y - 1};
                colourInserter (temp);
                colourInserter (L"?", F_YELLOW);
                //stateArray [position.y - 1][position.x - 1] = currentState;
            } else
                if (position.y + 1 < rows)
                {
                    coordinateType temp {position.x - 1, position.y + 1};
                    colourInserter (temp);
                    colourInserter (L"?", F_YELLOW);
                    //stateArray [position.y + 1][position.x - 1] = currentState;
                }
            break;
        case 3:
            if (position.x - 1 > 2)
            {
                coordinateType temp {position.x - 1, position.y + 1};
                colourInserter (temp);
                colourInserter (L"?", F_YELLOW);
                //stateArray [position.y + 1][position.x - 1] = currentState;
            } else
                if (position.x + 1 < columns)
                {
                    coordinateType temp {position.x + 1, position.y + 1};
                    colourInserter (temp);
                    colourInserter (L"?", F_YELLOW);
                    //stateArray [position.y + 1][position.x + 1] = currentState;
                }
            break;
        case 4:
            if (position.y - 1 > 2)
            {
                coordinateType temp {position.x + 1, position.y - 1};
                colourInserter (temp);
                colourInserter (L"?", F_YELLOW);
                //stateArray [position.y - 1][position.x + 1] = currentState;
            } else
                if (position.y + 1 < rows)
                {
                    coordinateType temp {position.x + 1, position.y + 1};
                    colourInserter (temp);
                    colourInserter (L"?", F_YELLOW);
                    //stateArray [position.y + 1][position.x + 1] = currentState;
                }
            break;
    }

};


const coordinateType& TheArea::getDimension (void)
{

    return startPoints [1];

};
