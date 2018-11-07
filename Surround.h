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
  Surround ();
  void allCouter (void);
  void colourInserter (std::string, WORD, COORD);
  void newSetter (void);
};


#endif // !SURROUND_H
