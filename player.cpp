#include "player.h"

#include <time.h>


const PINS Player::GetRoll(const PinSet& pins) const
{
  srand(time(NULL));
  float kPlayer = ((float(average))/(float(PERFECT_GAME)/2));
  kPlayer *= kPlayer*K;
  float sum;
  UINT8 total;
  for(PIN_ID p = 0; p < N_PINS; p++)
  {
    if(!pins.getPin(p))
      continue;
    
    sum += pins.getAverageDist(p);
    total++;
  }
  
  float endPerc = sum/total * (1+(standDev*(getRand()-0.5)));  //modified to a random effect depending on your consistency
  endPerc = (kPlayer-endPerc)/kPlayer;  //end distance probability
  endPerc *= pins.getPinCount();
  endPerc = roundf(endPerc);
  
  return endPerc>10? 10:(endPerc<0? 0:endPerc);
}
