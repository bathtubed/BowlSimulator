#include "scoresheet.h"

void printScoreSheet(const PlayerGame &game, ostream& out)
{
  const UINT8 frame_length = 7, name_length = 10, last_length = 12;
  out<<' ';
  out<<setw(frame_length*(N_FRAMES-1)+name_length+last_length)<<setfill('_')<<' '<<endl;
  
  out<<'|'<<setw(10)<<setfill(' ')<<'|';
  
  for(UINT8 f = 0; f < N_FRAMES-1; f++)
    out<<setw(3)<<setfill(' ')<<'|'<<(game.GetFrame(f).isStrike()? '*':' ')<<' '<<(game.GetFrame(f).GetMark()? '*':' ')<<'|';
  
  if(game.GetFrame(N_FRAMES-1).isStrike())
    out<<"* *|";
  else
    out<<"   |";
  
  if(game.GetFrame(N_FRAMES-1).isSpare())
    out<<"  *|";
  else if(game.GetFrame(N_FRAMES-1).isStrike() && game.GetFrame(N_FRAMES).isStrike())
    out<<"* *|";
  else
    out<<"   |";
  
  if(!game.GetFrame(N_FRAMES-1).GetMark())
    out<<"   |";
  else if(game.GetFrame(N_FRAMES-1).isStrike() && game.GetFrame(N_FRAMES).isStrike())
  {
    if(game.GetFrame(N_FRAMES+1).isStrike())
      out<<"* *|";
    else
      out<<"   |";
  }
  else if(game.GetFrame(N_FRAMES-1).isSpare())
  {
    if(game.GetFrame(N_FRAMES).isStrike())
      out<<"* *|";
    else
      out<<"   |";
  }
  else if(game.GetFrame(N_FRAMES).isSpare())
  {
    out<<"  *|";
  }
  else
  {
    out<<"   |";
  }
  
  
  out<<endl<<'|';
  out<<setw(9)<<setfill(' ')<<game.GetPlayer().GetName()<<'|';
  for(UINT8 f = 0; f < N_FRAMES-1; f++)
  {
    if(game.GetFrame(f).isStrike())
      out<<setw(3)<<setfill(' ')<<'|';
    else
      out<<setw(2)<<setfill(' ')<<int(game.GetFrame(f).GetFirst())<<'|';
    
    out<<setw(2)<<setfill(' ');
    if(game.GetFrame(f).GetMark())
      out<<'*';
    else if(game.GetFrame(f).GetSpare() == 0)
      out<<'-';
    else
      out<<game.GetFrame(f).GetSpare();
    
    out<<" |";
  }
  
  if(game.GetFrame(N_FRAMES-1).isStrike())
    out<<" * |";
  else if(game.GetFrame(N_FRAMES-1).GetFirst() == 0)
    out<<" - |";
  else
    out<<' '<<game.GetFrame(N_FRAMES-1).GetFirst()<<" |";
  
  if(game.GetFrame(N_FRAMES-1).isSpare())
    out<<" * |";
  else if(game.GetFrame(N_FRAMES-1).isStrike() && game.GetFrame(N_FRAMES).isStrike())
    out<<" * |";
  else if(game.GetFrame(N_FRAMES-1).isStrike())
  {
    if(game.GetFrame(N_FRAMES).GetFirst() == 0)
      out<<" - |";
    else
      out<<' '<<game.GetFrame(N_FRAMES).GetFirst()<<" |";
  }
  else if(!game.GetFrame(N_FRAMES-1).GetMark())
  {
    if(game.GetFrame(N_FRAMES-1).GetSpare() == 0)
      out<<" - |";
    else
      out<<' '<<game.GetFrame(N_FRAMES-1).GetSpare()<<" |";
  }
  
  if(!game.GetFrame(N_FRAMES-1).GetMark())
    out<<" - |";
  else if(game.GetFrame(N_FRAMES-1).isSpare())
  {
    if(game.GetFrame(N_FRAMES).isStrike())
      out<<" * |";
    else if(game.GetFrame(N_FRAMES-1).GetBonus() == 0)
      out<<" - |";
    else
      out<<' '<<game.GetFrame(N_FRAMES-1).GetBonus()<<" |";
  }
  else if(game.GetFrame(N_FRAMES).isSpare())
    out<<" * |";
  else if(game.GetFrame(N_FRAMES).isStrike())
  {
    if(game.GetFrame(N_FRAMES+1).isStrike())
      out<<" * |";
    else if(game.GetFrame(N_FRAMES-1).GetBonus() == 0)
      out<<" - |";
    else
      out<<' '<<game.GetFrame(N_FRAMES-1).GetBonus()<<" |";
  }
  else
  {
    if(game.GetFrame(N_FRAMES-1).GetBonus() == 0)
      out<<" - |";
    else
      out<<' '<<game.GetFrame(N_FRAMES-1).GetBonus()<<" |";
  }
  
  out<<endl<<'|';
  out<<setw(10)<<setfill(' ')<<'|';
  for(UINT8 f = 0; f < N_FRAMES-1; f++)
    out<<setw(3)<<setfill(' ')<<'|'<<(game.GetFrame(f).GetMark()? '*':' ')<<' '<<(game.GetFrame(f).isStrike()? '*':' ')<<'|';
  
  if(game.GetFrame(N_FRAMES-1).isStrike())
    out<<"* *|";
  else
    out<<"   |";
  
  if(game.GetFrame(N_FRAMES-1).isSpare())
    out<<"*  |";
  else if(game.GetFrame(N_FRAMES-1).isStrike() && game.GetFrame(N_FRAMES).isStrike())
    out<<"* *|";
  else
    out<<"   |";
  
  if(!game.GetFrame(N_FRAMES-1).GetMark())
    out<<"   |";
  else if(game.GetFrame(N_FRAMES-1).isStrike() && game.GetFrame(N_FRAMES).isStrike())
  {
    if(game.GetFrame(N_FRAMES+1).isStrike())
      out<<"* *|";
    else
      out<<"   |";
  }
  else if(game.GetFrame(N_FRAMES-1).isSpare())
  {
    if(game.GetFrame(N_FRAMES).isStrike())
      out<<"* *|";
    else
      out<<"   |";
  }
  else if(game.GetFrame(N_FRAMES).isSpare())
  {
    out<<"*  |";
  }
  else
  {
    out<<"   |";
  }
  
  out<<endl<<'|';
  out<<setw(10)<<setfill(' ')<<'|';
  
  for(UINT8 f = 0; f < N_FRAMES-1; f++)
    out<<setw(frame_length)<<setfill(' ')<<"|___|";
  
  out<<setw(last_length)<<setfill('_')<<'|';
  
  out<<endl<<'|';
  out<<setw(10)<<setfill(' ')<<'|';
  PINS total = 0;
  for(UINT8 f = 0; f < N_FRAMES; f++)
  {
    total += game.GetFrame(f).GetTotal();
    out<<setw((f==N_FRAMES-1? last_length:frame_length)-2)<<setfill(' ')<<total<<" |";
  }
  
  out<<endl<<'|';
  out<<setw(10)<<setfill('_')<<'|';
  for(UINT8 f = 0; f < N_FRAMES; f++)
    out<<setw(f==N_FRAMES-1? last_length:frame_length)<<setfill('_')<<'|';
  
  out<<endl;
}