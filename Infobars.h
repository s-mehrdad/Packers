// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,13.06.2022</changed>
// ********************************************************************************

#ifndef INFOBARS_H
#define INFOBARS_H


#include "Shared.h"


class titleBar :public Inserter
{
private:
  std::string titleSentence;
  coordinateType startPoint;
public:
  titleBar ( coordinateType areaGrid ); //parameter: area dimension
};


class guideBar :public Inserter
{
private:
  std::string signs [3];
  std::string guides [3];
  coordinateType startPoint;
public:
  guideBar ( coordinateType areaGrid ); //parameter: area dimension
};


#endif //INFOBARS_H
