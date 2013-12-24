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
  PINS rolls[23] = {0};
  Frame game[N_FRAMES+2];
  int p;
  int rslt;
  UINT8 r = 0;
  for(UINT8 f = 0; f < N_FRAMES; f++)
  {
    std::cout<<"Frame "<<int(f+1)<<std::endl;
    std::cout<<"First Roll: ";
    std::cin>>p;
    std::cin.ignore(999, '\n');
    rolls[r] = p;
    switch(rslt = game[f].Roll(rolls+(r++)))
    {  
      break;
      
    case Frame::STRIKE:
      std::cout<<"Strike!"<<std::endl;
    case Frame::SUCCESS:
      printPins(game[f].GetPinSet());
      std::cout<<"Roll Spare: ";
      std::cin>>p;
      std::cin.ignore(999, '\n');
      rolls[r] = p;
      if((rslt = game[f].Roll(rolls+(r++))) >= 0)
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
  
  if(game[N_FRAMES-1].GetMark())
  {
    int frame = 0;
    for(UINT8 bonuses = (rslt == Frame::STRIKE? 2:1); bonuses > 0; bonuses--, frame++)
    {
      std::cout<<"Bonus Ball: ";
      std::cin>>p;
      std::cin.ignore(999, '\n');
      rolls[r] = p;
      switch(rslt=game[N_FRAMES+frame].Roll(rolls+(r++)))
      {
      case Frame::STRIKE:
	std::cout<<"Strike!"<<std::endl;
	break;
      case Frame::SUCCESS:
	if(bonuses == 2)
	  frame--;
	break;
      case Frame::FAIL:
	std::cerr<<"You fucked up the roll in the bonus round, come on now."<<std::endl;
	return -1;
      }
    }
  }
  
  PINS total = 0;
  
  for(UINT8 g = 0; g < N_FRAMES; g++)
    total += game[g].GetTotal();
    
  std::cout<<"Your Score "<<int(total)<<std::endl;
  
  return 0;
}