#include "enemy.h"

Enemy::Enemy(){}

Enemy::Enemy(std::string name, int max_hp, int patk, int exp_rate, int gold_rate)
	: Entity(name)
{
	_hp       = max_hp;
	_max_hp   = max_hp;
	_attack_power = patk;
	_exp      = exp_rate;
	_gold     = gold_rate;
}

Enemy::~Enemy(){}
