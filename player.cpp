#include "player.h"

bool Player::loaded = false;
float Player::weights[] = {0};

const PINS GetRoll(const PinSet& pins) const
{
  float kPlayer = K*((average-PERFECT_GAME/2)/(PERFECT_GAME/2));
  float sum;
  UINT8 total;
  for(PIN_ID p = 0; p < N_PINS; p++)
  {
    if(!pins.getPin(p))
      continue;
    
    sum += getAverageDist(p);
    total++;
  }
  
  float endPerc = (kPlayer-sum/total)/kPlayer;  //end distance probability
  endPerc += standDev*(getRand()-0.5);  //modified to a random effect depending on your consistency
  endPerc *= pins.getPinCount();
  
  return endPerc;
}
