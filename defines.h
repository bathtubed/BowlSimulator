#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdlib.h>
#include <cstdlib>
#include <iostream>

// Generic Types
typedef unsigned char UINT8;
typedef unsigned short UINT16;

// Specific Types
typedef UINT16 AVG;
typedef UINT8 PIN_ID;
typedef char PINS;

inline float getRand() {return float(rand())/float(RAND_MAX);};

// Important constants
#define N_PINS 10
#define N_FRAMES 10

// Important Files
#define PIN_WEIGHTS "pin_weights.txt"



#endif /*_HEADER_H_*/