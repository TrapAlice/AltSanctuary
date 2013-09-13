#ifndef _STATE_GAMEMODE_H
#define _STATE_GAMEMODE_H

#include "gamestate.h"

class State_GameMode : public iGameState{
public:
	void Render( World *w, Renderer *r );
	void Update( Stack<iGameState*> *s, World *w, char c );
};

#endif