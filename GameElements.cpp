// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,14.06.2022</created>
/// <changed>ʆϒʅ,20.06.2022</changed>
// ********************************************************************************

#include "Packers.h"
#include "GameElements.h"


GameElement::GameElement ( void )
{

    elementID = nullptr;
    elementName = nullptr;
    sceneNumber = nullptr;
    elementStartPoint = nullptr;
    elementRow = nullptr;
    elementFloat = nullptr;

};


GameElement* GameElement::setGet ( void )
{
    return this;
};


void GameElement::setElementId ( short& id )
{
    *elementID = id;
};


short*& GameElement::setGetElementId ( void )
{
    return elementID;
};


std::string*& GameElement::setGetElementName ( void )
{
    return elementName;
};


short*& GameElement::setGetsceneNumber ( void )
{
    return sceneNumber;
};


coordinateType*& GameElement::setGetElementStartPoint ( void )
{
    return elementStartPoint;
};


short*& GameElement::setGetElementRow ( void )
{
    return elementRow;
};


std::string*& GameElement::setGetElementFloat ( void )
{
    return elementFloat;
};


void GameElement::release ( void )
{

    elementID = nullptr;
    elementName = nullptr;
    sceneNumber = nullptr;
    elementStartPoint = nullptr;
    elementRow = nullptr;
    elementFloat = nullptr;

};


GameElements::GameElements ( void )
{

    for ( char i = 0; i < 20; i++ )
    {
        gameElements [i] = nullptr;
    }
    //setElement = 0;
    elementsCount = 0;
    paddingShort = 1;
    paddingMedium = 2;
    paddingLong = 3;

};


void GameElements::release ( void )
{

    for ( short i = 0; i < elementsCount - 1; i++ )
    {
        gameElements [i] = nullptr;
    }

};


void GameElements::set ( GameElement* element )
{

    gameElements [elementsCount] = element;
    element->setElementId ( elementsCount );
    elementsCount++;

};


GameElement& GameElements::get ( short& id )
{
    return *gameElements [id];
};
