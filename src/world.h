#ifndef _WORLD_H
#define _WORLD_H

#include <memory>

class Act;
class Character;

class World{
public:
	World();
	~World();
	Character&      Player() const;
	void            SetPlayer(std::unique_ptr<Character>& c);
	Act&            GetCurrentAct() const;
	void            UseHealingCharge();
	void            RestoreHealingCharge();
	int             GetHealingCharges() const;
private:
	std::unique_ptr<Character> _player;
	std::unique_ptr<Act>       _current_act;
	int             _healing_charge;
};

#endif