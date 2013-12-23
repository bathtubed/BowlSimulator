#ifndef _FRAME_H_
#define _FRAME_H_

#include "pinset.h"

class frame
{
public:
  enum {FIRST=0, SECOND, COMPLETE} Stage_t;
  enum {ROLL=0, SPARE, BONUS};
  
private:
  Stage_t stage;
  bool mark;
  PinSet pins;
  PINS *roll;
  mutable PINS total;
  
public:
  const Stage_t getStage() const {return stage;};
  const PINS GetTotal() const {return mark? (roll[ROLL] + roll[SPARE] + roll[BONUS]):(roll[ROLL] + roll[SPARE]);};
  const PinSet GetPinSet() const {return pins;};
  void Roll(PINS * const n);
  
  frame(roll * const init=NULL): roll(init) {};
  
};




#endif /*_FRAME_H_*/