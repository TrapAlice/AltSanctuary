#ifndef _ENTITY_H
#define _ENTITY_H

#include <string>

//class Condition;

class Entity{
public:
	Entity();
	Entity(std::string name);
	virtual ~Entity();
	void            TakeDamage(const double& damage);
	std::string     Name() const;
	int             Hp() const;
	int             MaxHp() const;
	int             MinPower() const;
	int             MaxPower() const;
	int             AttackPower() const;
	int             getGold() const;
	int             getExp() const;
	void            IncreaseGold(int amount);
	void            IncreaseExp(int amount);
protected:
	std::string     _name;
	int             _hp;
	int             _max_hp;
	int             _attack_power;
	int             _exp;
	int             _gold;
};

#endif