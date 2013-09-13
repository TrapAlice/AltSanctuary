#ifndef _STATE_SKILLSWAP_H
#define _STATE_SKILLSWAP_H

#include "gamestate.h"

class State_SkillSwap : public iGameState{
public:
	State_SkillSwap();
	void Render( World *w, Renderer *r );
	void Update( Stack<iGameState*> *s, World *w, char c );
private:
	bool  select_;
	int   skill_pos_;
};


#endif