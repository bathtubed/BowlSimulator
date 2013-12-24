#ifndef _GAME_H_
#define _GAME_H_

#include "frame.h"
#include <vector>

using std::vector;


class Game
{
public:
  typedef PINS *ROLLS;
  typedef vector<Frame> FRAME_SET
  
private:
  ROLLS rollStream;
  FRAME_SET frames;
  mutable PINS total;
  
public:
  Game(UINT8 nFrames): total(0), ROLLS(new PINS [2*nFrames+1]) {};
  const PinSet& GetPinset() const {return frames.back().GetPinset();};
  const PinSet& GetPinset(const UINT8 i) const {return frames[i >= frames.size()? frames.size()-1:i].GetPinset();};
  const UINT8 GetCurFrame() const {return frames.size()-1;};
  const int Roll(const PIN_ID &n);
};



#endif /*_GAME_H_*/