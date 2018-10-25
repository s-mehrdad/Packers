#pragma once


#ifndef PACKER_H
#define PACKER_H


struct queueFeed {
  std::string str;
  WORD colour;
  COORD position;
  unsigned short delay;
};


class Packer {
  char Sign;
public:
  bool RchanceL;
  COORD position;
  unsigned short state;
  Packer (unsigned char);
  static void movementColourCout (std::list<queueFeed>, unsigned short);
  static void sortToQueues (void);
  static void addToQueues (std::string, WORD, COORD, unsigned short);
  static void hMovement (std::list<Packer>);
};


#endif // !PACKER_H