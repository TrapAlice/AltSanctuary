#include "condition.h"
#include "entity.h"
#include "conditionid.h"
#include "condition_function.cc"
#include "dbg.h"

Condition::Condition(int ticks, bool permanent, void (*condition_function)(double*, Entity*, Entity*, int), int activation_conditon, int optional){
	ticks_remaining_      = ticks;
	permanent_            = permanent;
	condition_function_   = condition_function;
	activation_condition_ = activation_conditon;
	active_               = true;
	x_                    = optional;
}

void Condition::ActivateAttacks(double *damage, Entity* attacker, Entity* defender){
	if( activation_condition_ == on_attack ) (condition_function_)(damage, attacker, defender, x_);
}

void Condition::ActivateDamaged(double *damage, Entity* attacker, Entity* defender){
	if( activation_condition_ == on_damaged ) (condition_function_)(damage, attacker, defender, x_);
}

void Condition::ActivateTick(Entity *attacker, Entity *defender){
	if( activation_condition_ == on_tick ) (condition_function_)(0, attacker, defender, x_);
	ticks_remaining_--;
	if( ticks_remaining_ == 0 ){
		active_ = false;
	}
}

void Condition::Clear(){
	delete this;
}

bool Condition::isActive(){
	return active_;
}

bool Condition::isPermanent(){
	return permanent_;
}

bool Condition::isRemovable(){
	return (!isActive() && !isPermanent());
}

#define CONDITION(id, ticks, permanent, function, activation, optional) \
case id: return( new Condition(ticks, permanent, function, activation, optional) )

Condition* Condition::CreateCondition(int condition_id, int optional){
	switch( condition_id ){
		CONDITION(Condition_Ranger_Poison,        5, false, &ranger_poison,        on_tick,   optional);
		CONDITION(Condition_Ranger_HealTier1,     1, false, &ranger_healtier1,     on_tick,   optional);
		CONDITION(Condition_Ranger_HealTier2,     2, false, &ranger_healtier2,     on_tick,   optional);
		CONDITION(Condition_Ranger_HealTier3,     3, false, &ranger_healtier3,     on_tick,   optional);
		CONDITION(Condition_Ranger_HealTier4,     4, false, &ranger_healtier4,     on_tick,   optional);
		CONDITION(Condition_Ranger_CripplingShot, 2, false, &ranger_cripplingshot, on_attack, optional);
		CONDITION(Condition_Ranger_Preparation,   2, false, &ranger_preparation,   on_attack, optional);
	}
	log_err("Invalid Condition Id");
	return NULL;
}
