#ifndef _CONDITION_H
#define _CONDITION_H

class Entity;

enum condition_activation{
	on_tick,
	on_attack,
	on_damaged,
};

class Condition{
public:
	static Condition* CreateCondition(int condition_Id, int = 0);
	Condition(int ticks, bool permanent, void (*condition_function)(double*, Entity*, Entity*, int), int, int);
	void ActivateAttacks(double *damage, Entity*, Entity*);
	void ActivateDamaged(double *damage, Entity*, Entity*);
	void ActivateTick(Entity*, Entity*);
	void Clear();
	bool isActive();
	bool isPermanent();
	bool isRemovable();
private:
	int    ticks_remaining_;
	bool   permanent_;
	void (*condition_function_)(double*, Entity*, Entity*, int);
	int    activation_condition_;
	bool   active_;
	int    x_;
};

#endif