// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.12.2018</created>
/// <changed>ʆϒʅ,01.04.2019</changed>
// ********************************************************************************

#include "pch.h"


#include <mutex>
#include <condition_variable>
#include <algorithm>

std::mutex MuTeX;
std::condition_variable conditionVariable;
bool ready;

void muTex ()
{
  // set to wait till awakening signal is received
  {
    std::unique_lock<std::mutex> uniqueLock ( MuTeX );
    conditionVariable.wait ( uniqueLock, [] { return ready; } );
  }

  // sending the awakening signal
  {
    std::unique_lock<std::mutex> uniqueLock ( MuTeX );
    ready = true;
    conditionVariable.notify_one ();
  }
}