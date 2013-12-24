#include "game.h"

const int Game::Roll(const PIN_ID &n)
{
  
  if(frames.size() > nFrames)
  {
    if(!frames[frames.size()-2].GetMark())
      return END;
    
    if(frames.size() > nFrames + 2)
      return END;
    
    if(frames.size() > nFrames + 1 && rollStream[rollStream.size()-1] < N_PINS && rollStream[rollStream.size()-2] < N_PINS)
      return END;
  }
  
  rollStream.push_back(n);
  
  if(frames.empty())
    frames.push_back(NULL);
  
  switch(frames.back().Roll(&rollStream.back()))
  {
  case Frame::STRIKE:
    if(frames.back().GetStage() == Frame::COMPLETE)
      frames.push_back(NULL);
    return STRIKE;
    
  case Frame::SUCCESS:
    if(frames.back().GetStage() == Frame::COMPLETE)
      frames.push_back(NULL);
    
    if(frames.back().GetMark())
      return SPARE;
    else
      return SUCCESS;
    
  case Frame::FAIL:
    return FAIL;
  }
}

const PINS Game::GetTotal() const
{
  total = 0;
  for(FRAME_SET::const_iterator i = frames.begin(); i != frames.end(); i++)
  {
    total += i->GetTotal();
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


