#ifndef _STATE_COMBAT
#define _STATE_COMBAT

#include "gamestate.h"

class Skill;
class Enemy;

class State_Combat : public iGameState {
public:
	State_Combat();
	State_Combat( Enemy* );
	~State_Combat();
	void Render( World *w, Renderer *r );
	void Update( Stack<iGameState*> *s, World *w, char c );
private:
	void _PlayerAttack( World *w, Skill *skill );
	int skill_offset_;
	int player_position_;
	bool repositioning_;
	Enemy *current_enemy_;
};

#endif
