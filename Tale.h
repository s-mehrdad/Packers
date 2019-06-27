// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.04.2019</created>
/// <changed>ʆϒʅ,27.06.2019</changed>
// ********************************************************************************

#pragma once


#include "Shared.h"


#ifndef TALE_H
#define TALE_H


class Tale : public Inserter
{
private:
  std::string title;
  WORD colour;
public:
  Tale ();
};


class Narrator : public Inserter
{
private:
  std::string title;
  WORD colour;
  std::string sentences [3];
  COORD startPoint;
public:
  Narrator ();
};


class Giant : public Inserter
{
private:
  std::string title;
  std::string theGiant [38];
  WORD colourOne;
  WORD colourTwo;
  WORD colourThree;
  std::string sentances [2];
  COORD startPoints [2];
public:
  Giant ();
};


//class Tale
//{
//  struct storyLine;
//  struct creatures;
//
//public:
//  Tale ( unsigned char );
//  void newSetter ( void );
//
//};


#endif // !TALE_H
