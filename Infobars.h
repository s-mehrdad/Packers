// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,20.06.2019</changed>
// ********************************************************************************

#pragma once


#ifndef INFOBARS_H
#define INFOBARS_H


#include "Shared.h"


class titleBar :public Inserter
{
private:
  std::string titleSentence;
  WORD colour;
  COORD startPoint;
public:
  titleBar ();
};


class guideBar
{
private:

public:
  guideBar ();
};


#endif //INFOBARS_H
