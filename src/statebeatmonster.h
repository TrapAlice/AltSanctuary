#pragma once

#include "gamestate.h"

class Enemy;

class State_BeatMonster : public iGameState{
public:
	State_BeatMonster();
	State_BeatMonster(Enemy e);
	void            Render( World& w, Renderer& r );
	void            Update( GameStateStack& s, World& w, const char& c );
private:
	int             _gold_drop;
	int             _exp_drop;
};