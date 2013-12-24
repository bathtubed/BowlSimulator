#include "player.h"

int main(int argc, char **argv)
{
  if(argc != 5 && argc != 4)
  {
    std::cout<<"call like dis"<<std::endl<<"playerTest <name> <average> <consistency> <pinout=1111111111>"<<std::endl;
    return -1;
  }
  
  Player me(argv[1], atoi(argv[2]), atof(argv[3]));
  PinSet pins;
  if(argc == 5)
  {
    for(PIN_ID id = 0; argv[4][id] != NULL; id++)
    {
      if(argv[id] == 0)
        pins.knockDown(PinSet::maskPin(id));
    }
  }
  
  std::cout<<me.GetName()<<" threw a "<<me.GetRoll(pins)<<" so congratu-fucking-lations"<<std::endl;
  return 0;
}