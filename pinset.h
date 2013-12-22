#ifndef _PINSET_H_
#define _PINSET_H_

#include "defines.h"

class PinSet
{
private:
  UINT16 pins; // bitfield
public:
  PinSet(UINT16 init): pins(init) {};
  PinSet(const PinSet& other): pins(other.pins) {};
  PinSet(): pins(2<<10 - 1) {};
  static const UINT16 maskPin(const PIN_ID id) {return 2<<id;};  // applies bit mask for pinset pin
  static const float GetWeight(const PIN_ID id);
  void resetPins(); // sets pins to have all 10 pins up
  bool getPin(const PIN_ID id) const; // returns state of pin at id
  void knockDown(const UINT16 p); // exclusive or's p with pins, knocking them down
  const PINS getPinCount() const;  // returns number of up pins
};



#endif /*_PINSET_H_*/