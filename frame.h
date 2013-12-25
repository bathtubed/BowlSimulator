#ifndef _FRAME_H_
#define _FRAME_H_

#include "pinset.h"

class Frame
{
public:
  typedef enum {FIRST=0, SECOND, COMPLETE} Stage_t;
  enum {ROLL=0, SPARE, BONUS};
  enum {FAIL=-1, SUCCESS, STRIKE};
  
private:
  Stage_t stage;
  bool mark;
  PinSet pins;
  PINS *roll;
  mutable PINS total;
  
public:
  const Stage_t GetStage() const {return stage;};
  const PINS GetTotal() const {return total = (mark? (roll[ROLL] + roll[SPARE] + roll[BONUS]):(roll[ROLL] + roll[SPARE]));};
  const PINS GetFirst() const;
  const PINS GetSpare() const;
//  const PINS GetBonus() const;
  const PinSet &GetPinSet() const {return pins;};
  const bool GetMark() const {return mark;};
  const bool isStrike() const {return roll[ROLL] == N_PINS;};
  const bool isSpare() const {return GetMark() && !isStrike();};
  const int Roll(PINS * const n);
  
  Frame(PINS * const init=NULL): roll(init), stage(FIRST), mark(false), total(0) {};
  
};




#endif /*_FRAME_H_*/