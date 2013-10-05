#include "skill.h"
#include "character.h"
#include "dbg.h"
#include "enemy.h"
#include "skill_function.cc"
#include <sstream>
#include <iostream>

Skill::Skill(std::string name, SkillType type, void (*skill_function)(int&, Character&, Enemy*), std::string(*summary_function)(const Character&)){
	_name             = name;
	_skill_function   = skill_function;
	_summary_function = summary_function;
	_type = type;
}

Skill::Skill(){
	_name = "Error";
	_skill_function = &barbarian_cleave;
	_summary_function = &barbarian_cleave_summary;
	_type = SkillType::STARTER;
}

int Skill::Attack(Character &character, Enemy *enemy){
	int damage_delt = -1;
	(_skill_function)(damage_delt, character, enemy);
	return damage_delt;
}

std::string Skill::Name(){ return( _name ); }

std::string Skill::Type(){
	switch( _type ){
		case SkillType::STARTER:
			return "(Starter---)";
		case SkillType::LINKER:
			return "(--Linker--)";
		case SkillType::FINISHER:
			return "(--Finisher)";
		case SkillType::HEAL:
			return "(---Heal---)";
		case SkillType::REPOSITION:
			return "-Restore MP-";
		case SkillType::ULTIMATE:
			return "(--Ultimate)";
	}
	return "ERROR";
}

std::string Skill::GetSummary(const Character& c){
	return (_summary_function)(c);
}

#define SKILL(id, name, type, skill_function, summary_function) \
case id: return( Skill(name, type, skill_function, summary_function) )

Skill Skill::CreateSkill(enum SKILL skill_id){
	switch( skill_id ){
		SKILL(SKILL::REPOSITION,              "-Reposition-",    SkillType::REPOSITION, &reposition, &reposition_summary);
		SKILL(SKILL::BARBARIAN_CLEAVE,        "Cleve",           SkillType::STARTER, &barbarian_cleave, &barbarian_cleave_summary);
		SKILL(SKILL::BARBARIAN_EXBASH,        "EX Bash",         SkillType::LINKER, &barbarian_exbash, &barbarian_exbash_summary);
		SKILL(SKILL::BARBARIAN_WHIRLWIND,     "Whirlwind",       SkillType::STARTER, &barbarian_whirlwind, &barbarian_whirlwind_summary);
		SKILL(SKILL::BARBARIAN_EXWHIRLWIND,   "EX Whirlwind",    SkillType::LINKER, &barbarian_exwhirlwind, &barbarian_exwhirlwind_summary);
		SKILL(SKILL::BARBARIAN_FRENZY,        "Frenzy",          SkillType::STARTER, &barbarian_frenzy, &barbarian_frenzy_summary);
		SKILL(SKILL::BARBARIAN_SIESMICSLAM,   "Siesmic Slam",    SkillType::LINKER, &barbarian_siesmicslam, &barbarian_siesmicslam_summary);
		SKILL(SKILL::FINALBLOW,               "Final Blow",      SkillType::FINISHER, &finalblow, &finalblow_summary);
	}
	return Skill();
}