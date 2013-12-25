#ifndef _MATCH_H_
#define _MATCH_H_


#include "playerGame.h"

class Match
{
public:
  typedef vector<PlayerGame> GAME_LIST;
  
private:
  GAME_LIST games;
  UINT8 turn;
  
public:
  Match(const vector<string> &playerFiles, const UINT8 nF);
  Match(const vector<Player> &players, const UINT8 nF);
  
public:
  const GamePlayer &GetGame(const UINT8 p) const {return games[p];};
  const UINT8 GetNPlayers() const {return games.size();};
  void Play();
};

#endif /*_MATCH_H_*/