#include "frame.h"

void printPins(const PinSet& pins)
{
  std::cout<<"Pins arranged from 1 thru "<<N_PINS<<std::endl;
  for(PIN_ID p = 0; p < N_PINS; p++)
  {
    std::cout<<pins.getPin(p);
  }
  std::cout<<std::endl;
}

int main(void)
{
  PINS rolls[21] = {0};
  Frame game[10];
  int p;
  int rslt;
  for(UINT8 f = 0, r = 0; f < N_FRAMES; f++)
  {
    std::cout<<"Frame "<<int(f)<<std::endl;
    std::cout<<"First Roll: ";
    std::cin>>p;
    rolls[r] = p;
    switch(game[f].Roll(rolls+(r++)))
    {  
    case Frame::STRIKE:
      std::cout<<"Strike!"<<std::endl;
      break;
      
    case Frame::SUCCESS:
      printPins(game[f].GetPinSet());
      std::cout<<"Roll Spare: ";
      std::cin>>p;
      rolls[r] = p;
      if(game[f].Roll(rolls+(r++)) >= 0)
      {
	break;
      }
      
    case Frame::FAIL:
      std::cerr<<"Error at Roll"<<std::endl;
      return -1;
     
    }
    
    if(game[f].GetPinSet().getPinCount() == 0 && game[f].GetStage() == Frame::SECOND)
      std::cout<<"Spare!"<<std::endl;
    
    printPins(game[f].GetPinSet());
  }
  return 0;
}