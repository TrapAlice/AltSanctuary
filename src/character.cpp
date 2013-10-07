#include "character.h"
#include "class.h"
#include "dbg.h"
#include "race.h"
#include "skill.h"
#include <stdlib.h>


Character::Character(const Class& class_type, const Race& race, const std::string& name, const int& personality, const bool& isMale)
	: Entity(name)
	, _class(class_type)
	, _race(race)
	, _is_male(isMale)
	, _gold(0)
{
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
		case Class::NOCLASS:
		default:
			break;
	}

	_max_hp         = (_vitality * _vitality_mod) * (1 + 0.01 * _vitality);
	_hp             = _max_hp;
	_attack_power   = _strength * _power_mod;
	_armor_value    = 0;

	if( _race == Race::HUMAN ){
		_max_mp += 10;
	}
	_mp = _max_mp;

	AddSkill(Skill::CreateSkill(SKILL::REPOSITION));
	AddSkill(Skill::CreateSkill(SKILL::BARBARIAN_CLEAVE));
	AddSkill(Skill::CreateSkill(SKILL::BARBARIAN_WHIRLWIND));
	AddSkill(Skill::CreateSkill(SKILL::BARBARIAN_FRENZY));
	AddSkill(Skill::CreateSkill(SKILL::BARBARIAN_EXBASH));
	AddSkill(Skill::CreateSkill(SKILL::BARBARIAN_EXWHIRLWIND));
	AddSkill(Skill::CreateSkill(SKILL::BARBARIAN_SIESMICSLAM));
	AddSkill(Skill::CreateSkill(SKILL::FINALBLOW));
}

Character::~Character()
{
}

std::string Character::ClassName() const{
	return CLASS_NAME(_class);
}

std::string Character::getRaceName() const{
	return RACE_NAME(_race);
}

void Character::AddSkill(const Skill skill){
	_skill_library.push_back(skill);
}

const Skill& Character::GetSkill(const int& pos) const{
	return _skill_library[pos];
}

bool Character::EnoughMp(const int& amount) const{
	return _mp >= amount;
}

void Character::RestoreMp(const int& amount){
	_mp += amount;
	if( _mp > _max_mp ){
		_mp = _max_mp;
	}
}

void Character::UseMp(const int& amount){
	_mp = _mp < amount ? 0 : _mp-amount;
}

void Character::IncreaseCombo(){
	++_combo_count;
}

void Character::ResetCombo(){
	_combo_count = 0;
}

int Character::PowerMulti(const double& multiplier) const{
	return _attack_power * multiplier;
}

void Character::IncreaseGold(int amount)
{
	_gold += amount;
}


int        Character::Str() const        { return( _strength ); }
int        Character::PowerMod() const   { return _power_mod; }
int        Character::Dex() const        { return( _dexterity ); }
int        Character::Int() const        { return( _intelligence ); }
int        Character::Vit() const        { return( _vitality ); }
int        Character::VitMod() const     { return _vitality_mod; }
int        Character::Wis() const        { return( _wisdom ); }
int        Character::Power() const      { return( _attack_power ); }
int        Character::Mp() const         { return( _mp ); }
int        Character::MaxMp() const      { return( _max_mp ); }
int        Character::SkillLibrarySize() const { return( _skill_library.size() ); }
int        Character::Level() const      { return 1; }
int        Character::ComboCount() const { return _combo_count; }
Race       Character::getRace() const    { return _race; }
std::string Character::getGender() const { return _is_male? "Male" : "Female";}
int        Character::getGold() const    { return _gold; }

void Character::_BarbarianInit(const int& personality){
	_strength     = 30 - (personality == 1)*3 + (personality == 2)*6;
	_dexterity    = 8  + (personality == 1)*5 - (personality == 3)*2;
	_intelligence = 1;
	_vitality     = 30 - (personality == 2)*4 + (personality == 3)*3;
	_wisdom       = 1;
	_attack_mod   = 20;
	_vitality_mod = 20;
	_power_mod    = 2;
	_max_mp       = 50;
}

void Character::_PaladinInit(const int& personality){
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

void Character::_AssassinInit(const int& personality){
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

void Character::_WizardInit(const int& personality){
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

void Character::_DruidInit(const int& personality){
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

void Character::_RangerInit(const int& personality){
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
