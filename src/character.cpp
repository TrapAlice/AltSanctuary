#include "character.h"
#include "skill.h"
#include "inventory.h"
#include "class.h"
#include "race.h"
#include <stdlib.h>
#include "dbg.h"

Character::Character(Class class_type, Race race, std::string name){
	skills_ = NULL;
	inv_ = NULL;
	_class = class_type;
	_name = name;
	switch( _class ){
		case Class::BARBARIAN:
			_BarbarianInit();
			break;
		case Class::PALADIN:
			_PaladinInit();
			break;
		case Class::ASSASSIN:
			_AssassinInit();
			break;
		case Class::WIZARD:
			_WizardInit();
			break;
		case Class::RANGER:
			_RangerInit();
			break;
		case Class::DRUID:
			_DruidInit();
			break;
		default:
			break;
	}

	max_hp_         = vitality_ * vitality_mod_;
	hp_             = max_hp_;
	attack_power_   = strength_ * power_mod_;
	max_initiative_ = 100;

	skills_ = new Skill*[8];	
	AddSkill(Skill::CreateSkill(skill_ranger_poisonarrow));
	AddSkill(Skill::CreateSkill(skill_ranger_salve));
	AddSkill(Skill::CreateSkill(skill_ranger_strongdraw));
	AddSkill(Skill::CreateSkill(skill_ranger_firstaid));
	AddSkill(Skill::CreateSkill(skill_ranger_cripplingshot));
	AddSkill(Skill::CreateSkill(skill_ranger_preparation));
	AddSkill(Skill::CreateSkill(skill_ranger_magicalarrow));
	AddSkill(Skill::CreateSkill(skill_ranger_steadyshot));
	SetSkill(0, 0);
	SetSkill(1, 1);
	SetSkill(2, 2);
	SetSkill(3, 3);
	SetSkill(4, 4);
	SetSkill(5, 5);
	SetSkill(6, 6);
	SetSkill(7, 7);
	inv_ = new Inventory();
}

Character::~Character(){
	if( skills_ ) delete skills_;
	if( inv_ )    delete inv_;
}

std::string Character::Class(){
	switch( class_type_ ){
		case CLASS_BARBARIAN:
			return( "Barbarian" );
		case CLASS_PALADIN:
			return( "Paladin" );
		case CLASS_ASSASSIN:
			return( "Assassin" );
		case CLASS_WIZARD:
			return( "Wizard" );
		case CLASS_RANGER:
			return( "Ranger" );
		case CLASS_DRUID:
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

void Character::_BarbarianInit(){
	strength_     = 15;
	dexterity_    = 6;
	intelligence_ = 0;
	vitality_     = 26;
	vitality_mod_ = 28;
	power_mod_    = 3;
}

void Character::_PaladinInit(){
	strength_     = 16;
	dexterity_    = 0;
	intelligence_ = 11;
	vitality_     = 26;
	vitality_mod_ = 26;
	power_mod_    = 3;
}

void Character::_AssassinInit(){
	strength_     = 12;
	dexterity_    = 16;
	intelligence_ = 0;
	vitality_     = 20;
	vitality_mod_ = 26;
	power_mod_    = 3;
}

void Character::_WizardInit(){
	strength_     = 21;
	dexterity_    = 0;
	intelligence_ = 31;
	vitality_     = 16;
	vitality_mod_ = 26;
	power_mod_    = 1;
}

void Character::_RangerInit(){
	strength_     = 11;
	dexterity_    = 16;
	intelligence_ = 0;
	vitality_     = 15;
	vitality_mod_ = 24;
	power_mod_    = 3;
}

void Character::_DruidInit(){
	strength_     = 13;
	dexterity_    = 0;
	intelligence_ = 6;
	vitality_     = 31;
	vitality_mod_ = 32;
	power_mod_    = 2;
}
