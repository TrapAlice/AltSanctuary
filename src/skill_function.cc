#include "enemy.h"
#include "character.h"
#include "condition.h"
#include "conditionid.h"
#include "dbg.h"

void ranger_poisonarrow(int *damage, Character* c, Enemy* e){
	e->GainCondition(Condition::CreateCondition(Condition_Ranger_Poison, c->Str()));
}

void ranger_salve(int *damage, Character* c, Enemy* e){
	float dex_scale;
	float atk_mod;
	if( c->Initiative() <= 20 ){
		dex_scale = 0.5;
		atk_mod   = 0.9;
	} else if( c->Initiative() <= 40 ){
		dex_scale = 0.75;
		atk_mod   = 0.8;
	} else if( c->Initiative() <= 60 ){
		dex_scale = 1;
		atk_mod   = 0.7;
	} else {
		dex_scale = 1.5;
		atk_mod   = 0.6;
	}

	*damage += c->Dex() * dex_scale;
	*damage += c->Power() * atk_mod;
}

void ranger_firstaid(int *damage, Character* c, Enemy* e){
	if( c->Initiative() <= 20 ){
		c->GainCondition(Condition::CreateCondition(Condition_Ranger_HealTier1));
		c->AdjustInitiative(-20);
	} else if( c->Initiative() <= 40 ){
		c->GainCondition(Condition::CreateCondition(Condition_Ranger_HealTier2));
		c->AdjustInitiative(-40);
	} else if( c->Initiative() <= 60 ){
		c->GainCondition(Condition::CreateCondition(Condition_Ranger_HealTier3));
		c->AdjustInitiative(-60);
	} else {
		c->GainCondition(Condition::CreateCondition(Condition_Ranger_HealTier4));
		c->AdjustInitiative(-80);
	}
}

void ranger_cripplingshot(int *damage, Character* c, Enemy* e){
	e->GainCondition(Condition::CreateCondition(Condition_Ranger_CripplingShot));
}

void ranger_preparation(int *damage, Character* c, Enemy* e){
	c->GainCondition(Condition::CreateCondition(Condition_Ranger_Preparation));
}

void ranger_magicalarrow(int *damage, Character* c, Enemy* e){
	*damage += c->Power() * (1.5 + c->Initiative()/50);
	c->TakeDamage(-*damage*0.05);
}