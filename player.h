#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <math.h>

#include "pinset.h"

using std::string;

class Player
{
  string name;
  PINS average;
  float standDev;  // this is a percentage of the mean found
public:
  Player(const string &n, const PINS avg, const float c): name(n), average(avg), standDev(c) {};
  Player(): average(0), standDev(0.0) {};
  void SetName(const string& n) {name = n;};
  const string& GetName() const {return name;};
  void SetAverage(const PINS &avg) {average = avg;};
  const PINS &GetAverage() const {return average;};
  void SetDev(const float dev) {standDev = dev;};
  const float GetDev() const {return standDev;};
  
public:
  const PINS GetRoll(const PinSet& pins) const;
};


#endif /*_PLAYER_H_*/