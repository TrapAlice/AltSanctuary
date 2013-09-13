#ifndef _STATE_CHARACTERSELECT_H
#define _STATE_CHARACTERSELECT_H

#include "gamestate.h"

class State_CharacterSelect : public iGameState{
public:
	void Render( World *w, Renderer *r );
	void Update( Stack<iGameState*> *s, World *w, char c );
};

#endif