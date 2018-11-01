#pragma once


#ifndef PACKER_H
#define PACKER_H


struct queueFeed {
  unsigned short delay;
  std::string str;
  WORD colour;
  COORD position;
  bool operator< (const queueFeed &a) const {
    return (delay < a.delay);
  };
};


class Packer {
  char Sign;
public:
  bool RchanceL;
  COORD position;
  unsigned short state;
  Packer (unsigned char);
  static void movementCout (void);
  static void addToQueues (std::string, WORD, COORD, unsigned short);
  static void hMovement (std::list<Packer>);
};


#endif // !PACKER_H