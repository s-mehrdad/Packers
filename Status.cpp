// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,15.07.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
#include "Status.h"
#include "Shared.h"
#include "Console.h"


Status::Status ( const unsigned char& mode )
{
  state = u8".: demo ^.^ :.";
  title = u8"status ^,^";
  pointState = { SCREEN_W - 16, 1 };
  pointTitle = { SCREEN_W - 15, 3 };
  otherString [0] = u8"packers:";
  otherString [1] = u8"age:";
  otherString [2] = u8"resources->";
  otherString [3] = u8"healthy:";
  otherString [4] = u8"renewing:";
  otherString [5] = u8"vanished:";
  otherString [6] = u8"packages->";
  otherString [7] = u8"have:";
  otherString [8] = u8"need:";
  otherPoints [0] = { SCREEN_W - 15, 5 };
  otherPoints [1] = { SCREEN_W - 15, 7 };
  otherPoints [2] = { SCREEN_W - 15, 10 };
  otherPoints [3] = { SCREEN_W - 15, 12 };
  otherPoints [4] = { SCREEN_W - 15, 15 };
  otherPoints [5] = { SCREEN_W - 15, 18 };
  otherPoints [6] = { SCREEN_W - 15, 21 };
  otherPoints [7] = { SCREEN_W - 15, 23 };
  otherPoints [8] = { SCREEN_W - 15, 26 };
  packersState = 0;
  agesIdentifier = mode;
  agesStrings [0] = u8"   Stone";
  agesStrings [1] = u8"   Middle";
  agesStrings [2] = u8"   Advanced";
  agesStrings [3] = u8"   Hollow";
  agesStrings [4] = u8"   Dirty";
  healthyState = 0;
  renewedState = 0;
  vanishedState = 0;
  haveState = 0;
  needState = 0;


  // game state
  colourInserter ( state, F_bWHITE, pointState );


  // statusBar
  colourInserter ( title, F_bWHITE, pointTitle );

  COORD coordinate { otherPoints [0] };
  colourInserter ( otherString [0], F_bPURPLE, coordinate );
  coordinate.X += 9;
  colourInserter ( std::to_string ( packersState ), F_bBLUE, coordinate );

  coordinate = otherPoints [1];
  colourInserter ( otherString [1], F_bPURPLE, coordinate );
  coordinate.Y += 1;
  colourInserter ( agesStrings [agesIdentifier], F_bBLUE, coordinate );

  colourInserter ( otherString [2], F_bWHITE, otherPoints [2] );
  coordinate = otherPoints [3];
  colourInserter ( otherString [3], F_bGREEN, coordinate );
  coordinate.X += 3;
  coordinate.Y += 1;
  colourInserter ( std::to_string ( healthyState ), F_bBLUE, coordinate );
  coordinate = otherPoints [4];
  colourInserter ( otherString [4], F_YELLOW, coordinate );
  coordinate.X += 3;
  coordinate.Y += 1;
  colourInserter ( std::to_string ( renewedState ), F_bBLUE, coordinate );
  coordinate = otherPoints [5];
  colourInserter ( otherString [5], F_RED, coordinate );
  coordinate.X += 3;
  coordinate.Y += 1;
  colourInserter ( std::to_string ( vanishedState ), F_bBLUE, coordinate );

  colourInserter ( otherString [6], F_bWHITE, otherPoints [6] );
  coordinate = otherPoints [7];
  colourInserter ( otherString [7], F_bPURPLE, coordinate );
  coordinate.X += 3;
  coordinate.Y += 1;
  colourInserter ( std::to_string ( haveState ), F_bBLUE, coordinate );
  coordinate = otherPoints [8];
  colourInserter ( otherString [8], F_bPURPLE, coordinate );
  coordinate.X += 3;
  coordinate.Y += 1;
  colourInserter ( std::to_string ( needState ), F_bBLUE, coordinate );
  //TODO add: random need setter
};


void Status::get ( const unsigned short& arg )
{
  COORD coordinate { otherPoints [0] };
  coordinate.X += 9;
  packersState = arg;
  colourInserter ( std::to_string ( packersState ), F_bBLUE, coordinate );
}


void Status::setter ( const unsigned char& input )
{
  //TODO add: a set of state setter
  // update complete the state setter
  COORD coordinate { otherPoints [1] };
  coordinate.Y += 1;
  colourInserter ( u8"            ", F_bBLUE, coordinate );
  colourInserter ( agesStrings [input], F_bBLUE, coordinate );
};
