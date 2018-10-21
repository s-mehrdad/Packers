#pragma once


#ifndef PACKER_H
#define PACKER_H


struct queueFeed {
  std::string str;
  WORD colour;
  COORD position;
  unsigned short mode;
};
//std::list<queueFeed> QQ1;
//std::list<queueFeed> QQ2;


class Packer {
  char Sign;
public:
  bool RchanceL;
  COORD position;
  unsigned short state;
  Packer (unsigned short);
  static void addToQueues (std::string, WORD, COORD, unsigned char);
  static void PackerP (std::list<queueFeed>, unsigned short);
  static void hQuickMovement (std::list<Packer>, unsigned char);
  static void hNormalMovement (std::list<Packer>, unsigned char);
  static void hSlowMovement (std::list<Packer>, unsigned char);
};


#endif // !PACKER_H