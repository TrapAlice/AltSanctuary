#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <string>

#include "entity.h"

enum class Class;
enum class Race;

class Skill;
class Inventory;

class Character : public Entity{
public:
	Character(Class class_type, Race race, std::string name, int personality);
	~Character();
	std::string ClassName();
	double      Str();
	double      Dex();
	double      Int();
	double      Vit();
	double      Wis();
	int         Power();
	double      Initiative();
	double      MaxInitiative();
	void        AdjustInitiative( int amount );
	void        AddSkill( Skill* skill );
	void        SetSkill( int pos, int libraryPos );
	Inventory*  Inv();
	Skill*      GetSkill( int pos );
	int         SkillLibrarySize();
	std::string SkillSummary( int pos );
private:
	Class       _class;
	Race        _race;
	std::string _name;
	double      _strength;
	double      _dexterity;
	double      _intelligence;
	double      _vitality;
	double      _wisdom;
	double      _power_mod;
	double      _vitality_mod;
	double      _attack_mod;
	double      _mp;
	double      _max_mp;
	double      _armor_value;
	Inventory *inv_;
	Skill    **skills_;
	std::vector<Skill*> skill_library_;
	
	void _BarbarianInit(int personality);
	void _PaladinInit(int personality);
	void _AssassinInit(int personality);
	void _WizardInit(int personality);
	void _RangerInit(int personality);
	void _DruidInit(int personality);
};

#endif
