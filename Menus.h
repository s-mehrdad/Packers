// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,13.10.2019</changed>
// ********************************************************************************

#ifndef MENUS_H
#define MENUS_H


#include "Shared.h"


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


class agesMenu :public Inserter
{
private:
  std::string title;
  std::string options [5];
  std::string selectionSign;
  unsigned char selected;
  bool set { false };
  COORD startPoints [2];
public:
  agesMenu ();
  void switcher ();
  void switchSet ( const unsigned char&, const bool& );
  const unsigned char& get ();
};


class charactersMenu :public Inserter
{
private:
  std::string title;
  std::string options [2];
  std::string selectionSign;
  unsigned char selected;
  bool set { false };
  COORD startPoints [2];
public:
  charactersMenu ();
  void switcher ();
  void switchSet ( const unsigned char&, const bool& );
  const unsigned char& get ();
};


class motivationsMenu :public Inserter
{
private:
  std::string title;
  std::string options [6];
  WORD colours [6];
  std::string selectionSign;
  unsigned char selected;
  bool set { false };
  COORD startPoints [2];
public:
  motivationsMenu ();
  void switcher ();
  void switchSet ( const unsigned char&, const bool& );
  const unsigned char& get ();
};


#endif //MENUS_H
