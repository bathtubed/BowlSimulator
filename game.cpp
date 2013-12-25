#include "game.h"

const int Game::Roll(const PIN_ID &n)
{
  int rtrn;
  rollStream.push_back(n);
  
  if(frames.empty())
    frames.push_back(NULL);
  
  switch(frames.back().Roll(&rollStream.back()))
  {
  case Frame::STRIKE:
    if(frames.back().GetStage() == Frame::COMPLETE)
      frames.push_back(NULL);
    
    rtrn = STRIKE;
    break;
    
  case Frame::SUCCESS:
    if(frames.back().GetStage() == Frame::COMPLETE)
    {
      frames.push_back(NULL);
      
      if(frames[frames.size()-2].GetMark())
        rtrn = SPARE;
      else
        rtrn = SUCCESS;
    }
    else
    {
      if(frames.back().GetMark())
        rtrn = SPARE;
      else
        rtrn = SUCCESS;
    }
    break;
    
  case Frame::FAIL:
    return FAIL;
  }
  
  if(bonuses > 0)
  {
    if(--bonuses == 0)
      return END;
  }
  
  if(frames.size() == nFrames+1 && bonuses == 0)
  {
    bonuses = (rtrn == STRIKE? 2:(rtrn == SPARE? 1:0));
  }
  
  if(frames.size() > nFrames && bonuses == 0)
  {
    return END;
  }
  
  return rtrn;
      
}

const PINS Game::GetTotal() const
{
  total = 0;
  for(UINT8 i = 0; i < nFrames; i++)
  {
    total += frames[i].GetTotal();
  }
  
  return total;
}

void Game::ChangeFrames(const UINT8 i)
{
  nFrames = i;
  frames.clear();
  rollStream.clear();
  rollStream.reserve(2*i+1);
  frames.reserve(i+2);
  frames.push_back(NULL);
}


