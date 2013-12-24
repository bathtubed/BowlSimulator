#include <string>
#include <stdexcept>

#include "game.h"


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
  using std::cout;
  using std::cin;
  using std::endl;
  using std::cerr;
  using std::stoi;
  using std::invalid_argument;
  using std::out_of_range;

  Game myGame;
  int in;
  int rslt = Game::SUCCESS;
  string buf;
  while(rslt > Game::END)
  {
    cout<<"Frame "<<myGame.GetCurFrame();
    printPins(myGame.GetPinSet());
    cout<<"Roll: ";
    getline(cin, buf);
    try
    {
      in = stoi(buf);
    }
    catch(const invalid_argument ia)
    {
      cerr<<"You passed an invalid argument"<<endl;
      continue;
    }
    catch(const out_of_range oor)
    {
      cerr<<"Okay, the number should be between 0 and 10,"<<endl<<"let alone the monstruous number YOU must have typed"<<endl;
      continue;
    }
    cout<<endl;
    switch(rslt = myGame.Roll(in))
    {
    case Game::STRIKE:
      cout<<"Strike!"<<endl;
      break;
    case Game::SPARE:
      cout<<"Spare!"<<endl;
      break;
    case Game::SUCCESS:
      break;
    case Game::FAIL:
      cerr<<"Wat r u doin"<<endl;
      break;
    case Game::END:
      cout<<"All done yay!"<<endl;
      break;
    }
  }
  
  cout<<"You scored a "<<myGame.GetTotal()<<endl;
}