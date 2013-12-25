#include "playerGame.h"

const string PlayerGame::nameKey("name");
const string PlayerGame::averageKey("average");
const string PlayerGame::devKey("dev");
  

const bool PlayerGame::load(const string file)
{
  using std::stringstream;
  FILE *fp = fopen(file.c_str(), "r");
  if(fp == NULL)
    return false;
  
  char key[255] = "";
  char value[255] = "";
  char buf[255] = "";
  PINS ptmp;
  float ftmp;
  
  while(fscanf(fp, "%s\n", buf) != EOF)
  {
    stringstream ss;
    ss<<buf;
    ss.get(key, 255, ':');
    ss.ignore(1);
    ss.get(value, 255);
    if(!nameKey.compare(key))
    {
      p.SetName(value);
    }
    else if(!averageKey.compare(key))
    {
      try
      {
        ptmp = std::stoi(value);
      }
      catch(const std::exception &e)
      {
	fclose(fp);
	return false;
      }
      
      if(ptmp > 300)
	return false;
      
      p.SetAverage(ptmp);
    }
    else if(!devKey.compare(key))
    {
      try
      {
	ftmp = std::stof(value);
      }
      catch(const std::exception &e)
      {
	fclose(fp);
	return false;
      }
      
      if(ftmp < 0)
	return false;
      
      p.SetDev(ftmp);
    }
  }
  
  fclose(fp);
  return true;
}

const int PlayerGame::Roll()
{
  int rslt;
  if(!ready)
    return false;
  
  do
  {
    switch(rslt = Roll(p.GetRoll(GetPinSet())))
    {
    case STRIKE:
      if(GetBonuses() > 0)
      {
	rslt = SUCCESS;
	break;
      }
      
      return STRIKE;
      
    case SPARE:
      if(GetBonuses() > 0)
      {
	rslt = SUCCESS;
	break;
      }
      
      return SPARE;
      
    case SUCCESS:
      if(GetFrame(GetCurFrame()).GetStage() == Frame::SECOND)
      {
	rslt == SUCCESS;
	break;
      }
      
      return SUCCESS;
      
    default:
      return rslt;
    }
  } while(rslt == SUCCESS);
  
  return rslt;
}