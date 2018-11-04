#pragma once


#ifndef PACKER_H
#define PACKER_H


struct queueFeed {
  unsigned short delay;
  std::string str;
  WORD colour;
  COORD position;
  queueFeed () {
    delay = 2000;
    str = "NULL";
    colour = 0x00;
    position.X = 0;
    position.X = 0;
  }
  void set (unsigned short mode, std::string strCharacter, WORD Colour, COORD pos) {
    delay = mode;
    str = strCharacter;
    colour = Colour;
    position = pos;
  }
  bool operator< (const queueFeed &a) const {
    return (delay < a.delay);
  };
};


class Packer {
  char Sign;
public:
  bool RchanceL;
  COORD position;
  unsigned char id;
  unsigned short state;
  Packer (unsigned char);
  void moveCout (void);
  static void movementCout (void);
  static void addToQueues (unsigned short, std::string, WORD, COORD);
  static void hMovement (std::list<Packer>);
};


#endif // !PACKER_H