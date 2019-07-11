// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.04.2019</created>
/// <changed>ʆϒʅ,12.07.2019</changed>
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
  std::string sceneOne [3];
  std::string sceneTwo [2];
  std::string dAmSentences [3];
  COORD startPoint;
public:
  Narrator ();
  void insertion ( const unsigned short& );
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


#endif // !TALE_H
