#ifndef _STATE_COMBAT
#define _STATE_COMBAT

#include "gamestate.h"

class Character;
class Enemy;
class Skill;

class State_Combat : public iGameState {
public:
	State_Combat();
	State_Combat(Enemy*);
	~State_Combat();
	void            Render(World& w, Renderer& r);
	void            Update(GameStateStack& s, World& w, const char& c);
private:
	void            _Heal(Character& c);
	int             _HealValue(Character& c);
	void            _PlayerAttack(World& w, Skill& skill);
	int             _heals_used;
	int             skill_offset_;
	int             player_position_;
	Enemy           *current_enemy_;
	const Skill&    _Skill1(Character c);
	const Skill&    _Skill2(Character c);
	const Skill&    _Skill3(Character c);
	bool            _used_skill[3];
};

#endif
