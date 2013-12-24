#ifndef _PINSET_H_
#define _PINSET_H_

#include "defines.h"

class PinSet
{
private:
  UINT16 pins; // bitfield
  static bool loaded;
  static float weights[N_PINS];
  
public:
  PinSet(UINT16 init): pins(init) {};
  PinSet(const PinSet& other): pins(other.pins) {};
  PinSet() {resetPins();};
  static const UINT16 maskPin(const PIN_ID id) {return 2<<id;};  // applies bit mask for pinset pin
  static const float GetWeight(const PIN_ID id);
  void resetPins() {pins = (2<<N_PINS) - 1;}; // sets pins to have all 10 pins up
  const bool getPin(const PIN_ID id) const {return pins & maskPin(id);}; // returns state of pin at id
  const bool knockDown(const UINT16 p); // exclusive or's p with pins, knocking them down
  const PINS getPinCount() const;  // returns number of up pins
  const float getAverageDist(const PIN_ID id) const;
  const float getX(const PIN_ID id) const;
};



#endif /*_PINSET_H_*/