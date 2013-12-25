#include "frame.h"

const int Frame::Roll(PINS * const n)
{
  if(*n > pins.getPinCount() || n==NULL)
    return FAIL;
  if(stage == FIRST)
    roll = n;
  
  if(GetTotal() >= N_PINS && !mark)
    mark = true;
  
  PinSet a = pins;
  float sumWeights = 0.0, r;
  for(PIN_ID i = 0; i < N_PINS; i++)
  {
    if(!a.getPin(i))
      continue;
    sumWeights += PinSet::GetWeight(i)*(K-a.getAverageDist(i))/K;
  }
  
  float derp;
  
  for(PINS p = 0; p < *n; p++)
  {
    r = getRand() * sumWeights;
    for(PIN_ID q = 0; q < N_PINS; q++)
    {
      if(!pins.getPin(q))
	continue;
      
      r -= (derp = PinSet::GetWeight(q)*(K-a.getAverageDist(q))/K);
      
      if(r <= 0)
      {
	pins.knockDown(PinSet::maskPin(q));
	sumWeights -= derp;
	break;
      }
    }
  }	
  
  int rtrn;
  
  if(mark && stage==FIRST)
  {
    stage = COMPLETE;
    rtrn = STRIKE;
  }
  else if(mark && stage==SECOND)
  {
    stage = COMPLETE;
    rtrn = SUCCESS;
  }
  else if(stage == FIRST)
  {
    stage = SECOND;
    rtrn = SUCCESS;
  }
  else
  {
    stage = COMPLETE;
    rtrn = SUCCESS;
  }
  
  return rtrn;
}

const PINS Frame::GetFirst() const
{
  if(stage != COMPLETE)
    return N_PINS + 1;
  
  return roll[ROLL];
}

const PINS Frame::GetSpare() const
{
  if(stage != COMPLETE)
    return N_PINS + 1;
  
  if(isStrike())
    return N_PINS + 1;
  
  return roll[SPARE];
}

const PINS Frame::GetBonus() const
{
  if(!GetMark())
    return N_PINS + 1;
  return roll[BONUS];
}
