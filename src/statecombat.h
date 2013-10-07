#ifndef _STATE_COMBAT
#define _STATE_COMBAT

#include "gamestate.h"

#include <memory>

class Character;
class Enemy;
class Skill;

class State_Combat : public iGameState {
public:
	//State_Combat();
	State_Combat(std::unique_ptr<Enemy> enemy);
	~State_Combat();
	void            Render(World& w, Renderer& r);
	void            Update(GameStateStack& s, World& w, const char& c);
private:
	void            _Heal(Character& c);
	int             _HealValue(Character& c);
	void            _PlayerAttack(World& w, Skill& skill);
	std::unique_ptr<Enemy> _current_enemy;
	int             _heals_used;
	const Skill&    _Skill1(Character c);
	const Skill&    _Skill2(Character c);
	const Skill&    _Skill3(Character c);
	bool            _used_skill[3];
};

#endif
