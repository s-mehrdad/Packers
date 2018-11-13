// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,06.11.2018</created>
/// <changed>ʆϒʅ,13.11.2018</changed>
// ********************************************************************************

#pragma once


#ifndef SURROUND_H
#define SURROUND_H


class Surround {
  struct titelBar;
  struct menus;
  struct guideBar;
  struct statusBar;
  //struct infoBar;
  //bool running;
public:
  Surround (unsigned char);
  void newSetter (void);
  static void colourInserter (std::string, WORD, COORD);
  static void allCouter (void);
  static void menusSetter (unsigned short, bool);
};


#endif // !SURROUND_H