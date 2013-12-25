#include "playerGame.h"

int main(int argc, char **argv)
{
  using namespace std;
  
  if(argc < 2)
  {
    cout<<"Instructions"<<endl<<argv[0]<<" player1.txt player2.txt ... playerN.txt"<<endl;
    return -1;
  }
  
  for(UINT8 i = 1; i < argc; i++)
  {
    PlayerGame theirGame(argv[i], N_FRAMES);
    cout<<endl<<theirGame.GetPlayer().GetName()<<"has an average of "<<int(theirGame.GetPlayer().GetAverage());
    cout<<" and a deviant of "<<theirGame.GetPlayer().GetDev()<<endl;
    for(UINT8 f = 0; f < N_FRAMES; f++)
    {
      cout<<"Frame "<<int(f+1)<<endl;
      switch(theirGame.Roll())
      {
      case Game::STRIKE:
	cout<<endl<<"Strike!"<<endl;
	break;
	
      case Game::SPARE:
	cout<<endl<<"Spare!"<<endl;
	break;
	
      case Game::SUCCESS:
	break;
	
      case Game::FAIL:
      case Game::END:
	cerr<<"WAT!"<<endl;
	f=N_FRAMES;
	break;
      }
      
      cout<<int(theirGame.GetFrame(theirGame.GetCurFrame() - 1).GetFirst())<<" ";
      if(theirGame.GetFrame(theirGame.GetCurFrame() - 1).GetSpare() == N_PINS + 1)
	cout<<"-";
      else
	cout<<int(theirGame.GetFrame(theirGame.GetCurFrame() - 1).GetSpare());
      
      cout<<endl;
    }
    
    cout<<theirGame.GetPlayer().GetName()<<" scored a "<<theirGame.GetTotal()<<endl;
  }
  
}