// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,24.06.2019</changed>
// ********************************************************************************

#pragma once


#ifndef INFOBARS_H
#define INFOBARS_H


#include "Shared.h"


class titleBar :public Inserter
{
private:
  std::string titleSentence;
  COORD startPoint;
public:
  titleBar ();
};


class guideBar :public Inserter
{
private:
  std::string signs [3];
  std::string guides [3];
  COORD startPoint;
public:
  guideBar ();
};


#endif //INFOBARS_H
