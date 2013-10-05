#ifndef _ENTITY_H
#define _ENTITY_H

#include <string>
#include <vector>

//class Condition;

class Entity{
public:
	Entity();
	virtual ~Entity();
	void            TakeDamage(const double& damage);
	std::string     Name() const;
	int             Hp() const;
	int             MaxHp() const;
	int             MinPower() const;
	int             MaxPower() const;
	int             AttackBoost() const;
protected:
	std::string     name_;
	int             _hp;
	int             _max_hp;
	int             _attack_power;
};

#endif