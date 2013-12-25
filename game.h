#ifndef _GAME_H_
#define _GAME_H_

#include "frame.h"
#include <vector>

using std::vector;

class Game
{
public:
  typedef vector<PINS> ROLLS;
  typedef vector<Frame> FRAME_SET;
  enum {FAIL=-1, END=0, SUCCESS, STRIKE, SPARE};
  
private:
  ROLLS rollStream;
  FRAME_SET frames;
  UINT8 nFrames;
  UINT8 bonuses;
  mutable PINS total;
  
protected:
  const UINT8 GetBonuses() const {return bonuses;};
  
public:
  Game(const UINT8 nF=N_FRAMES): total(0), bonuses(0) {ChangeFrames(nF);};
  void ChangeFrames(const UINT8 i);
  const PinSet& GetPinSet() const {return frames.back().GetPinSet();};
  const PinSet& GetPinSet(const UINT8 i) const {return frames[i >= frames.size()? frames.size()-1:i].GetPinSet();};
  const UINT8 GetCurFrame() const {return frames.size()-1;};
  const Frame& GetFrame(const UINT8 f) const {return frames[f];};
  const int Roll(const PIN_ID &n);
  const PINS GetTotal() const;
};



#endif /*_GAME_H_*/