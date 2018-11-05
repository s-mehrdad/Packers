#pragma once


#ifndef SHARED_H
#define SHARED_H


extern bool running;
extern bool protectedSetCursor;

extern std::mutex m;
extern std::condition_variable cv;
extern bool bereitOne;
extern bool bereitTwo;


void loading (void);
void pressed (unsigned char[], bool);


#endif // !SHARED_H