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
      if(key >= N_PINS)
	continue;
      weights[key] = value;
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
  return p >= maskPin(N_PINS)? false:(pins ^= p? true:true);  //ouch that code tho
}

const PINS PinSet::getPinCount() const
{
  PINS rtrn=0;
  for(PIN_ID id = 0; id < N_PINS; id++)
    rtrn += (maskPin(id) & pins? 1:0);
  return rtrn;
}