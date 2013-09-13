#ifndef _STATE_INVENTORY_H
#define _STATE_INVENTORY_H

#include "gamestate.h"

class State_Inventory : public iGameState{
public:
	void Render( World *w, Renderer *r );
	void Update( Stack<iGameState*> *s, World *w, char c );
};

#endif
