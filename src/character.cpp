#include "character.h"
#include "skill.h"
#include "inventory.h"
#include "class.h"
#include "race.h"
#include <stdlib.h>
#include "dbg.h"

Character::Character(Class class_type, Race race, std::string name, int personality){
	skills_ = NULL;
	inv_ = NULL;
	_class = class_type;
	_name = name;
	switch( _class ){
		case Class::BARBARIAN:
			_BarbarianInit(personality);
			break;
		case Class::PALADIN:
			_PaladinInit(personality);
			break;
		case Class::ASSASSIN:
			_AssassinInit(personality);
			break;
		case Class::WIZARD:
			_WizardInit(personality);
			break;
		case Class::RANGER:
			_RangerInit(personality);
			break;
		case Class::DRUID:
			_DruidInit(personality);
			break;
		default:
			break;
	}

	_max_hp         = (_vitality * _vitality_mod) * (1 + 0.01 * _vitality);
	_hp             = _max_hp;
	_attack_power   = _strength * _power_mod;
	_armor_value    = 0;

	if( _race = Race::HUMAN ){
		_max_mp += 10;
	}
	_mp = _max_mp;
}

Character::~Character(){
	if( skills_ ) delete skills_;
	if( inv_ )    delete inv_;
}

std::string Character::ClassName(){
	switch( _class ){
		case Class::BARBARIAN:
			return( "Barbarian" );
		case Class::PALADIN:
			return( "Paladin" );
		case Class::ASSASSIN:
			return( "Assassin" );
		case Class::WIZARD:
			return( "Wizard" );
		case Class::RANGER:
			return( "Ranger" );
		case Class::DRUID:
			return( "Druid" );
	}
	return "";
}

void Character::AddSkill(Skill* skill){
	skill_library_.push_back(skill);
}

void Character::SetSkill(int pos, int libraryPos){
	skills_[pos] = skill_library_[libraryPos];
}

void Character::AdjustInitiative(int amount){
	initiative_ += amount;
	if( initiative_ > max_initiative_ ){
		initiative_ = max_initiative_;
	}
}

std::string Character::SkillSummary(int pos){
	if( skills_[pos] ){
		return skills_[pos]->GetSummary();
	}
	return "";
}

Skill* Character::GetSkill(int pos){
	return skills_[pos];
}

double     Character::Str()              { return( strength_ ); }
double     Character::Dex()              { return( dexterity_ ); }
double     Character::Int()              { return( intelligence_ ); }
double     Character::Vit()              { return( vitality_ ); }
double     Character::Wis()              { return( wisdom_ ); }
int        Character::Power()            { return( attack_power_ ); }
double     Character::Initiative()       { return( initiative_ ); }
double     Character::MaxInitiative()    { return( max_initiative_ ); }
Inventory* Character::Inv()              { return( inv_ ); }
int        Character::SkillLibrarySize() { return( skill_library_.size() ); }

void Character::_BarbarianInit(int personality){
	_strength     = 30 - (personality == 1)*3 + (personality == 2)*6;
	_dexterity    = 8  + (personality == 1)*5 - (personality == 3)*2;
	_intelligence = 1;
	_vitality     = 30 - (personality == 2)*4 + (personality == 3)*3;
	_wisdom       = 1;
	_attack_mod   = 20;
	_vitality_mod = 20;
	_power_mod    = 2;
	_max_mp       = 60;
}

void Character::_PaladinInit(int personality){
	_strength     = 6  + (personality == 2)*3 - (personality == 3)*4;
	_dexterity    = 1  + (personality == 1)*5;
	_intelligence = 9  - (personality == 1)*3;
	_vitality     = 31 - (personality == 2)*2 + (personality == 3)*6;
	_wisdom       = 23;
	_attack_mod   = 20 + _intelligence + _wisdom;
	_vitality_mod = 18;
	_power_mod    = 1;
	_max_mp       = 60;
}

void Character::_AssassinInit(int personality){
	_strength     = 6  - (personality == 2)*2 + (personality == 3)*5;
	_dexterity    = 35 + (personality == 1)*6 + (personality == 2)*3 - (personality == 3)*3;
	_intelligence = 1;
	_vitality     = 27 - (personality == 1)*4;
	_wisdom       = 1;
	_attack_mod   = 20 + _dexterity;
	_vitality_mod = 18;
	_power_mod    = 1;
	_max_mp       = 60;
}

void Character::_WizardInit(int personality){
	_strength     = 6  - (personality == 2)*2;
	_dexterity    = 1  + (personality == 3)*6;
	_intelligence = 28 + (personality == 1)*5 + (personality == 2)*3 - (personality == 3)*4;
	_vitality     = 27 - (personality == 1)*3;
	_wisdom       = 9;
	_attack_mod   = 20 + _intelligence + _wisdom;
	_vitality_mod = 18;
	_power_mod    = 1;
	_max_mp       = 80;
}

void Character::_DruidInit(int personality){
	_strength     = 28 + (personality == 1)*3 - (personality == 2)*4 - (personality == 3)*3;
	_dexterity    = 1;
	_intelligence = 1  - (personality == 1)*2 +  (personality == 2)*6;
	_vitality     = 31 + (personality == 3)*4;
	_wisdom       = 9;
	_attack_mod   = 20 + _intelligence;
	_vitality_mod = 22;
	_power_mod    = 2;
	_max_mp       = 60;
}

void Character::_RangerInit(int personality){
	_strength     = 13 - (personality == 2)*3 - (personality == 3)*2;
	_dexterity    = 28 + (personality == 1)*6 + (personality == 2)*5;
	_intelligence = 1;
	_vitality     = 27 - (personality == 1)*4 + (personality == 3)*3;
	_wisdom       = 1;
	_attack_mod   = 20 + _dexterity;
	_vitality_mod = 18;
	_power_mod    = 1;
	_max_mp       = 60;
}
