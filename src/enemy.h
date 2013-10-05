#ifndef _ENEMY_H
#define _ENEMY_H

#include "entity.h"

class Enemy : public Entity{
public:
	Enemy();
	Enemy(std::string name, int max_hp, double patk, double matk);
	~Enemy();
};

#endif
