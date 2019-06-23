// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,23.06.2019</changed>
// ********************************************************************************

#pragma once


#include "Shared.h"


#ifndef MENUS_H
#define MENUS_H


class dangerAreaMenu :public Inserter
{
private:
  std::string title;
  std::string options [3];
  std::string selectionSign;
  unsigned char selected;
  bool set { false };
  COORD startPoints [2];
public:
  dangerAreaMenu ();
  void switcher ();
  void switchSet ( const unsigned char&, const bool& );
  unsigned char& get ();
};


class ageMenu :public Inserter
{
private:
  std::string title;
  std::string options [5];
  std::string selectionSign;
  unsigned char selected;
  bool set { false };
  COORD startPoints [2];
public:
  ageMenu ();
  void switcher ();
  void switchSet ( const unsigned char&, const bool& );
};


class characterMenu :public Inserter
{
private:
  std::string title;
  std::string options [2];
  std::string selectionSign;
  unsigned char selected;
  bool set { false };
  COORD startPoints [2];
public:
  characterMenu ();
  void switcher ();
  void switchSet ( const unsigned char&, const bool& );
};


#endif //MENUS_H
