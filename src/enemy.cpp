#include "enemy.h"

Enemy::Enemy(){}

Enemy::Enemy(std::string name, int max_hp, double patk, double matk)
	: Entity(name)
{
	_hp       = max_hp;
	_max_hp   = max_hp;
	_attack_power = patk;
}

Enemy::~Enemy(){}
