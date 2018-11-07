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
  void set2 (unsigned short mode, std::string strCharacter, WORD Colour) {
    delay = mode;
    str = strCharacter;
    colour = Colour;
  }
  bool operator< (const queueFeed &a) const {
    return (delay < a.delay);
  }
};


class Packer {
  char Sign;
  unsigned char id;
  unsigned short state;
public:
  Packer *address;
  COORD position;
  bool RchanceL;
  queueFeed moves[4];
  Packer (unsigned char);
  void moveCout (void);
  static unsigned char count;
  static void movementCout (void);
  static void addToQueues (unsigned short, std::string, WORD, COORD);
  static void hMovement (std::list<Packer>);
};


#endif // !PACKER_H