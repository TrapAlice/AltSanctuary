#include "entity.h"
#include "dbg.h"

Entity::Entity()
{
}

Entity::Entity(std::string name)
	: _name(name)
{
}

Entity::~Entity()
{
}

void Entity::TakeDamage(const double& damage){
	_hp-=damage;
	if( _hp > _max_hp ){
		_hp = _max_hp;
	}
}

int Entity::MinPower() const{
	return _attack_power * 0.75;
}

int Entity::MaxPower() const{
	return _attack_power * 1.25;
}

int Entity::AttackPower() const{
	return rand() % (MaxPower() - MinPower() + 1) + MinPower();
}

std::string         Entity::Name() const  { return( _name ); }
int                 Entity::Hp() const    { return( _hp ); }
int                 Entity::MaxHp() const { return( _max_hp ); }
