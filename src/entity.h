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
	int         Hp() const;
	int         MaxHp() const;
	int         MinPower() const;
	int         MaxPower() const;
	int         AttackBoost() const;
	void        CycleConditions(int state, double *damage, Entity *attacker);
	void        GainCondition(Condition *condition);
	void        ClearConditions();
protected:
	std::string  name_;
	int          _hp;
	int          _max_hp;
	int         _attack_power;
	std::vector<Condition*> conditions_;
};

#endif