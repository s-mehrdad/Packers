// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,23.06.2022</changed>
// ********************************************************************************

#include "Packers.h"
#include "Area.h"


TheArea::TheArea(unsigned char age, std::string name) :
    currentAge(age),
    GameElement::GameElement()
{

    setBase();

    elementID = 0;
    elementName = name;
    firstInScene = 2;
    horizontalWall = u8"═"; // Unicode: "━"
    verticalWall = u8"║"; // Unicode: "┃"
    edges[0] = u8"╔"; // Unicode: "┏"
    edges[1] = u8"╚"; // Unicode: "┗"
    edges[2] = u8"╝"; // Unicode: "┛"
    edges[3] = u8"╗"; // Unicode: "┓"
    wallColour = F_CYAN;
    rows = SCREEN_H - 20;
    columns = SCREEN_W - 30;
    if (columns % 2 == 0)
        columns -= 1;
    if (rows % 2 == 0)
        rows -= 1;
    startPoints[0] = { 1, 1 };
    startPoints[1] = { columns, rows };
    resources[0] = u8"♠";
    resources[1] = u8"♣";
    resources[2] = u8"♦";
    healthyColour = F_GREEN;
    renewedColour = F_YELLOW;
    vanishedColour = F_bRED;
    inRow = 2;
    floatedTo = u8"left";

};


void TheArea::setBase(void)
{

    setGetElementId() = &elementID;
    setGetElementName() = &elementName;
    setGetsceneNumber() = &firstInScene;
    setGetElementStartPoint() = startPoints;
    setGetElementRow() = &inRow;
    setGetElementFloat() = &floatedTo;

};


void TheArea::draw()
{

    // area
    coordinateType position;
    setGetElementStartPoint() = &position;
    for (int y = 1; y <= rows; y++)
    {
        for (int x = 1; x <= columns; x++)
        {
            position.x = x;
            position.y = y;
            colourInserter(position);

            // first horizontal wall
            if (y == 1 && x != columns)
            {

                // left top edge
                if (y == 1 && x == 1)
                    colourInserter(edges[0], wallColour);
                colourInserter(horizontalWall, wallColour);
            }

            // right top edge
            if (y == 1 && x == columns)
                colourInserter(edges[3], wallColour);

            // left bottom edge
            if (y == rows && x == 1)
                colourInserter(edges[1], wallColour);

            // second horizontal wall
            if (y == rows && x != columns)
                colourInserter(horizontalWall, wallColour);
            else
                // right bottom edge
                if (y == rows && x == columns)
                    colourInserter(edges[2], wallColour);
                else

                    // vertical walls
                    if (x == 1 || x == columns)
                        if (y != 1)
                            colourInserter(verticalWall, wallColour);

            // packs
            if (y != 1 && y != rows && y % 2 == 0)
                if (x != 1 && x != columns && x % 2 == 0)
                    colourInserter(resources[1], healthyColour);
            std::cout << '\n';
        }
    }
};


void TheArea::setter(const unsigned short& state, const coordinateType& position)
{
    //TODO to be added: other resource colours + reconstruction
    int wish{ state };
    wish /= 10;

    switch (wish)
    {
    case 1:
        if (position.x - 1 > 2)
        {
            coordinateType temp{ position.x - 1, position.y - 1 };
            colourInserter(temp);
            colourInserter(u8"♣", F_YELLOW);
            //stateArray [position.y - 1][position.x - 1] = currentState;
        }
        else
            if (position.x + 1 < columns)
            {
                coordinateType temp{ position.x + 1, position.y - 1 };
                colourInserter(temp);
                colourInserter(u8"♣", F_YELLOW);
                //stateArray [position.y - 1][position.x + 1] = currentState;
            }
        break;
    case 2:
        if (position.y - 1 > 2)
        {
            coordinateType temp{ position.x - 1, position.y - 1 };
            colourInserter(temp);
            colourInserter(u8"♣", F_YELLOW);
            //stateArray [position.y - 1][position.x - 1] = currentState;
        }
        else
            if (position.y + 1 < rows)
            {
                coordinateType temp{ position.x - 1, position.y + 1 };
                colourInserter(temp);
                colourInserter(u8"♣", F_YELLOW);
                //stateArray [position.y + 1][position.x - 1] = currentState;
            }
        break;
    case 3:
        if (position.x - 1 > 2)
        {
            coordinateType temp{ position.x - 1, position.y + 1 };
            colourInserter(temp);
            colourInserter(u8"♣", F_YELLOW);
            //stateArray [position.y + 1][position.x - 1] = currentState;
        }
        else
            if (position.x + 1 < columns)
            {
                coordinateType temp{ position.x + 1, position.y + 1 };
                colourInserter(temp);
                colourInserter(u8"♣", F_YELLOW);
                //stateArray [position.y + 1][position.x + 1] = currentState;
            }
        break;
    case 4:
        if (position.y - 1 > 2)
        {
            coordinateType temp{ position.x + 1, position.y - 1 };
            colourInserter(temp);
            colourInserter(u8"♣", F_YELLOW);
            //stateArray [position.y - 1][position.x + 1] = currentState;
        }
        else
            if (position.y + 1 < rows)
            {
                coordinateType temp{ position.x + 1, position.y + 1 };
                colourInserter(temp);
                colourInserter(u8"♣", F_YELLOW);
                //stateArray [position.y + 1][position.x + 1] = currentState;
            }
        break;
    }
};


const coordinateType& TheArea::getDimension(void)
{
    return startPoints[1];
};
