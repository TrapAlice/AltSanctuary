#include "enemy.h"
#include "condition.h"

Enemy::Enemy(){}

Enemy::Enemy(std::string name, int max_hp, double patk, double matk){
	name_     = name;
	_hp       = max_hp;
	_max_hp   = max_hp;
	patk_  = patk;
	matk_ = matk;
	_attack_power = 50;
}

Enemy::~Enemy(){}
