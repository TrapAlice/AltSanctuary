#include "entity.h"
#include "condition.h"
#include "dbg.h"

Entity::Entity(){}

Entity::~Entity(){
	ClearConditions();
}

void Entity::TakeDamage(double damage){
	if( damage > 0 ){
		CycleConditions(3, &damage, NULL);
	}
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

int Entity::AttackBoost() const{
	return rand() % (MaxPower() - MinPower() + 1) + MinPower();
}

void Entity::CycleConditions(int state, double *damage, Entity *opponent){
	for( unsigned int x = 0; x < conditions_.size(); ++x ){
		switch( state ){
			case 1: //Tick
				conditions_[x]->ActivateTick(opponent, this);
				break;
			case 2: //Attack
				conditions_[x]->ActivateAttacks(damage, this, opponent);
				break;
			case 3: //Damaged
				conditions_[x]->ActivateDamaged(damage, opponent, this);
				break;
		}
		if( conditions_[x]->isRemovable() ){
			conditions_[x]->Clear();
			//delete conditions_[x];
			conditions_.erase(conditions_.begin()+x);
		}
	}
}

void Entity::GainCondition(Condition *condition){
	conditions_.push_back(condition);
}

void Entity::ClearConditions(){
		for( unsigned int x = 0; x < conditions_.size(); ++x ){
			if( !conditions_[x]->isPermanent() ){
				conditions_[x]->Clear();
				conditions_.erase(conditions_.begin()+x);
			}
	}
}

std::string Entity::Name()  { return( name_ ); }
int         Entity::Hp() const    { return( _hp ); }
int         Entity::MaxHp() const { return( _max_hp ); }
