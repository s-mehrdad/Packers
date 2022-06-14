// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,14.06.2022</created>
/// <changed>ʆϒʅ,14.06.2022</changed>
// ********************************************************************************

#ifndef GAMEELEMENTS_H
#define GAMEELEMENTS_H


#include "Shared.h"


class GameElement
{
private:
  short elementId;
  std::string elementName;
  short sceneNumber;
  coordinateType elementStartPoint;
  short elementRow;
  std::string elementFloat; //left, center, right, stretchedH, stretchedV
public:
  GameElement ( short elementId,
                std::string elementName,
                short sceneNumber,
                coordinateType elementStartPoint,
                short elementPosition,
                std::string elementFloat );
  GameElement* setGet (void);
  short& setGetElementId (void);
  std::string& setGetElementName (void);
  short& setGetsceneNumber (void);
  coordinateType& setGetElementStartPoint (void);
  short& setGetElementRow (void);
  std::string& setGetElementFloat (void);

  virtual void draw (void) {};
};


class GameElements
{
private:
  GameElement* gameElements [20];
  short setElement;
  short elementsCount;
  short paddingShort;
  short paddingMedium;
  short paddingLong;
public:
  GameElements (void);
  void release (void);

  void set ( GameElement* );
  GameElement& get (void);
};


#endif // !GAMEELEMENTS_H
