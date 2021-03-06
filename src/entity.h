#ifndef _ENTITY_H
#define _ENTITY_H

#include <string>
#include <vector>

class Condition;

class Entity{
public:
	Entity();
	virtual ~Entity();
	void        TakeDamage( double damage );
	std::string Name();
	int         Hp();
	int         MaxHp();
	void        CycleConditions(int state, double *damage, Entity *attacker);
	void        GainCondition(Condition *condition);
	void        ClearConditions();
protected:
	std::string  name_;
	int          hp_;
	int          max_hp_;
	std::vector<Condition*> conditions_;
};

#endif