// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,14.06.2022</created>
/// <changed>ʆϒʅ,14.06.2022</changed>
// ********************************************************************************

#include "Packers.h"
#include "GameElements.h"


GameElement::GameElement ( short id, std::string name,
                           short scene, coordinateType startPoint,
                           short row, std::string floated )
{

  elementId = id;
  elementName = name;
  sceneNumber = scene;
  elementStartPoint = startPoint;
  elementRow = row;
  elementFloat = floated;

};


GameElement* GameElement::setGet ( void )
{
  return this;
};


short& GameElement::setGetElementId ( void )
{
  return elementId;
};


std::string& GameElement::setGetElementName ( void )
{
  return elementName;
};


short& GameElement::setGetsceneNumber ( void )
{
  return sceneNumber;
};


coordinateType& GameElement::setGetElementStartPoint ( void )
{
  return elementStartPoint;
};


short& GameElement::setGetElementRow ( void )
{
  return elementRow;
};


std::string& GameElement::setGetElementFloat ( void )
{
  return elementFloat;
};


GameElements::GameElements ( void )
{

  for (char i = 0; i < 20; i++)
  {
    gameElements [i] = nullptr;
  }
  setElement = 0;
  elementsCount = 0;
  paddingShort = 1;
  paddingMedium = 2;
  paddingLong = 3;

};


void GameElements::release ( void )
{

};


void GameElements::set ( GameElement* element )
{
  gameElements [setElement] = element;
  setElement++;
};


GameElement& GameElements::get ( void )
{
  return *gameElements [0];
};
