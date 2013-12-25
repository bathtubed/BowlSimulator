#ifndef _PLAYER_GAME_H_
#define _PLAYER_GAME_H_

#include <exception>
#include <sstream>

#include "player.h"
#include "game.h"

class PlayerGame: public Game
{
public:
  static const string nameKey;
  static const string averageKey;
  static const string devKey;
  
public:
  using Game::Roll;
  
private:
  Player p;
  bool ready;
  
public:
  PlayerGame(const string file, const UINT8 nF=N_FRAMES): Game(nF), ready(load(file)) {};
  PlayerGame(const Player& initP, const UINT8 nF=N_FRAMES): Game(nF), p(initP), ready(true) {};
  const bool load(const string file);
  
public:
  const int Roll();
  const Player &GetPlayer() const {return p;};
};

#endif /*_PLAYER_GAME_H_*/