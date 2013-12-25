#include "playerGame.h"
#include "scoresheet.h"

#include <time.h>

int main(int argc, char **argv)
{
  using namespace std;
  
  srand(time(NULL));
  
  if(argc < 2)
  {
    cout<<"Instructions"<<endl<<argv[0]<<" player1.txt player2.txt ... playerN.txt"<<endl;
    return -1;
  }
  
  for(UINT8 i = 1; i < argc; i++)
  {
    PlayerGame theirGame(argv[i], N_FRAMES);
    for(UINT8 f = 0; f < N_FRAMES; f++)
    {
      switch(theirGame.Roll())
      {
      case Game::STRIKE:	
	break;
	
      case Game::SPARE:
	break;
	
      case Game::SUCCESS:
	break;
	
      case Game::FAIL:
      case Game::END:
	//cerr<<"WAT!"<<endl;
	f=N_FRAMES;
	break;
      }
    }
    
    printScoreSheet(theirGame, cout);
  }
  
}