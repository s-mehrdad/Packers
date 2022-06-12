// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,11.06.2022</changed>
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
  titleBar ();
};


class guideBar :public Inserter
{
private:
  std::string signs [3];
  std::string guides [3];
  coordinateType startPoint;
public:
  guideBar ();
};


#endif //INFOBARS_H
