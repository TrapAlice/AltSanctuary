#ifndef _ENEMY_H
#define _ENEMY_H

#include "entity.h"

class Enemy : public Entity{
public:
	Enemy();
	Enemy(std::string name, int max_hp, int patk, int exp_rate, int gold_rate);
	~Enemy();
private:
};

#endif
