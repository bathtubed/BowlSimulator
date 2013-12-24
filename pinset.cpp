#include "pinset.h"
#include <fstream>

bool PinSet::loaded = false;
float PinSet::weights[] = {0};

const float PinSet::GetWeight(const PIN_ID id)
{
  if(!loaded) // if it hasn't loaded yet
  {
//    std::fstream fs (PIN_WEIGHTS, std::fstream::in | std::fstream::out);
    FILE * fp = fopen(PIN_WEIGHTS, "r");
    if(fp == NULL)
      return -2.0;
    PIN_ID key;
    float value;
    while(fscanf(fp, "%d:%f", &key, &value) != EOF)
    {
      if(key > N_PINS)
	continue;
      weights[key-1] = value;
    }
    fclose(fp);
    loaded = true;
  }
  
  if(id >= N_PINS)
    return -1.0;
  
  return weights[id];  
}

const bool PinSet::knockDown(const UINT16 p)
{
  return p >= maskPin(N_PINS)? false:((pins ^= p)? true:true);  //ouch that code tho
}

const PINS PinSet::getPinCount() const
{
  PINS rtrn=0;
  for(PIN_ID id = 0; id < N_PINS; id++)
    rtrn += (maskPin(id) & pins? 1:0);
  return rtrn;
}

const float PinSet::getX(const PIN_ID id) const
{
  switch(id)
  {
  case 0:
    return 1.5;
  case 1:
    return 1.0;
  case 2:
    return 2.0;
  case 3:
    return 0.5;
  case 4:
    return 1.5;
  case 5:
    return 2.5;
  case 6:
    return 0.0;
  case 7:
    return 1.0;
  case 8:
    return 2.0;
  case 9:
    return 3.0;
  default:
    return -1.0;
  }
}

const float PinSet::getAverageDist(const PIN_ID id) const
{
  if(id >= N_PINS || !getPin(id))
    return 0.0;
  
  float sum = 0.0;
  PIN_ID total = 0;
  
  for(PIN_ID p = 0; p < N_PINS; p++)
  {
    if(p == id || !getPin(p))
      continue;
    sum += abs(getX(id) - getX(p));
    total++;
  }
  
  return sum/(total==0? 1:total);
}