// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,14.06.2022</changed>
// ********************************************************************************

#ifndef AREA_H
#define AREA_H


#include "Shared.h"
#include "GameElements.h"


class Area : public GameElement, Inserter
{
private:
  unsigned char age;
  std::string wallH;
  std::string wallV;
  std::string edges [4];
  WORD colourW;
  short rows;
  short columns;
  std::string resources [3];
  WORD colourH;
  WORD colourR;
  WORD colourV;
public:
  Area ( unsigned char ageMode, std::string elementName );
  void draw ( void );
  void setter ( const unsigned short&, const coordinateType& );
  const coordinateType getDimension ( void ); //area's dimension

  //static unsigned char stateArray [rows][columns]; // dynamic needed
};


#endif // !AREA_H
