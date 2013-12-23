#include "frame.h"

const bool Frame::Roll(PINS * const n)
{
  if(*n > pins.getPinCount() || n==NULL)
    return false;
  roll = n;
  float sumWeights = 0.0, r;
  for(PIN_ID i = 0; i < N_PINS; i++)
  {
    sumWeights += PinSet::GetWeight(i);
  }
  
  
  
  for(PINS p = 0; p < *n; p++)
  {
    r = getRand() * sumWeights;
    for(PIN_ID q = 0; q < N_PINS; q++)
    {
      if(!pins.getPin(q))
	continue;
      
      r -= PinSet::GetWeight(q);
      
      if(r <= 0)
      {
	pins.knockDown(PinSet::maskPin(q));
	sumWeights -= PinSet::GetWeight(q);
	break;
      }
            
    }
  }
  
  return true;
}