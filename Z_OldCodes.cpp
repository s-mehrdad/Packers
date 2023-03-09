
// ********************************************************************************
/// <summary>
/// Z_OldCodes.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 01.12.2018
/// </summary>
/// <created>ʆϒʅ, 01.12.2018</created>
/// <changed>ʆϒʅ, 09.03.2023</changed>
// ********************************************************************************

#include "Packers.h"
#include "Z_OldCodes.h"


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
