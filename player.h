#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

#include "pinset.h"

using std::string;

class Player
{
  static bool loaded;
  string name;
  PINS average;
  float standDev;  // this is a percentage of the mean found
public:
  Player(const string &n, const PINS avg, const float c): name(n), average(avg), consistency(c) {};
  Player(): average(0), consistency(0.0) {};
  void SetName(const string& n) {name = n;};
  const string& GetName() const {return name;};
  void SetAverage(const &avg) {average = avg;};
  const PINS &GetAverage() const {return average;};
  void SetDev(const float dev) {standDev = dev;};
  const float GetDev() const {return standDev;};
  
public:
  const PINS GetRoll(const PinSet& pins) const;
};


#endif /*_PLAYER_H_*/