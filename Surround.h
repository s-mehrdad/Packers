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
  void allCouter (void);
  void newSetter (void);
  void colourInserter (std::string, WORD, COORD);
};


#endif // !SURROUND_H
