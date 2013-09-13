#include "skill.h"
#include "character.h"
#include "enemy.h"
#include <sstream>
#include <iostream>
#include "skill_function.cc"
#include "dbg.h"

Skill::Skill(std::string name, double init, double damage, double atk_mod, int scale_stats, double scale_value, void (*skill_function)(int*, Character*, Enemy*)){
	name_           = name;
	init_           = init;
	damage_         = damage;
	atk_mod_        = atk_mod;	
	scale_stats_    = scale_stats;
	scale_value_    = scale_value;
	skill_function_ = skill_function;
}

int Skill::Attack(Character *character, Enemy *enemy){
	int damage_delt = 0;
	damage_delt += damage_;
	damage_delt += character->Power() * atk_mod_;
	if( scale_stats_ & SCALE_STR ) damage_delt += character->Str() * scale_value_;
	if( scale_stats_ & SCALE_DEX ) damage_delt += character->Dex() * scale_value_;
	if( scale_stats_ & SCALE_INT ) damage_delt += character->Int() * scale_value_;
//	if( scale_stats_ & SCALE_WIS ) damage_delt += character->Wis() * scale_value_;
	if( scale_stats_ & SCALE_VIT ) damage_delt += character->Vit() * scale_value_;
//	if( scale_stats_ & SCALE_TGH ) damage_delt += character->Tgh() * scale_value_;
	if( skill_function_ ){
		(skill_function_)(&damage_delt, character, enemy);
	}
	if( init_ ){
		character->AdjustInitiative(init_);
	}
	return damage_delt;
}

std::string Skill::Name(){ return( name_ ); }
double Skill::Init(){ return( init_ ); }
double Skill::Damage(){ return( damage_ ); }
double Skill::AtkMod(){ return( atk_mod_ ); }

std::string Skill::GetSummary(){
	std::ostringstream info;
	info << name_ <<" ( ";

	if( damage_ ){
		info << damage_ << "DMG ";
	}

	if( atk_mod_ ){
		info << 1+atk_mod_ << " xATK ";
	}

	if( init_ ){
		info << init_ << "ini ";
	}

	info << ")";

	return info.str();
}

#define SKILL(id, name, init, damage, atkmod, scaleStats, scaleValue, skill_function) \
case id: return( new Skill(name, init, damage, atkmod, scaleStats, scaleValue, skill_function) )

Skill* Skill::CreateSkill(int skill_id){
	switch( skill_id ){
		SKILL(skill_ranger_poisonarrow,   "Poison Arrow",   -20,  0,  0,    0,         0,    &ranger_poisonarrow);
		SKILL(skill_ranger_salve,         "Salve",          -10,  0,  0,    0,         0,    &ranger_salve);
		SKILL(skill_ranger_strongdraw,    "Strong Draw",    -20,  0,  2,    SCALE_DEX, 1,    NULL);
		SKILL(skill_ranger_firstaid,      "First Aid",      -20,  0,  0,    0,         0,    &ranger_firstaid);
		SKILL(skill_ranger_cripplingshot, "Crippling Shot",  20,  0,  0.25, 0,         0,    &ranger_cripplingshot);
		SKILL(skill_ranger_preparation,   "Preparation",    -10,  0,  0,    0,         0,    &ranger_preparation);
		SKILL(skill_ranger_magicalarrow,  "Magical Arrow",  -20,  0,  0,    SCALE_DEX, 0.35, &ranger_magicalarrow);
		SKILL(skill_ranger_frozenarrow,   "Frozen Shot",    -30,  0,  2,    SCALE_DEX, 0.2,  NULL);
		SKILL(skill_ranger_steadyshot,    "Steady Shot",     10,  0,  0.75, SCALE_DEX, 0.15, NULL);
	}
	return NULL;
}