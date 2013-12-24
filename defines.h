#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <stdlib.h>
#include <cstdlib>
#include <iostream>

// Generic Types
typedef unsigned char UINT8;
typedef unsigned short UINT16;

// Specific Types
typedef UINT8 PIN_ID;
typedef UINT16 PINS;

inline float getRand() {return float(rand())/float(RAND_MAX);};

template<class T>
inline float abs(T a) {return a > 0? a:-a;};

// Important constants
#define N_PINS 10
#define N_FRAMES 10
#define PERFECT_GAME 300
#define K 5.5

// Important Files
#define PIN_WEIGHTS "pin_weights.txt"



#endif /*_DEFINES_H_*/