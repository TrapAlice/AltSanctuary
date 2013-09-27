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
	Character(Class class_type, Race race, std::string name);
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
	double     strength_;
	double     dexterity_;
	double     intelligence_;
	double     vitality_;
	double     wisdom_;
	double     power_mod_;
	double     vitality_mod_;
	int        attack_power_;
	double     initiative_;
	double     max_initiative_;
	Inventory *inv_;
	Skill    **skills_;
	std::vector<Skill*> skill_library_;
	
	void _BarbarianInit();
	void _PaladinInit();
	void _AssassinInit();
	void _WizardInit();
	void _RangerInit();
	void _DruidInit();
};

#endif
