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
	int         Str();
	int         Dex();
	int         Int();
	int         Vit();
	int         Wis();
	int         Power();
	int         PowerMulti(double multipler);
	int         Mp();
	int         MaxMp();
	int         Level();
	bool        EnoughMp(int amount);
	void        UseMp(int amount);
	void        RestoreMp(int amount);
	void        IncreaseCombo();
	void        ResetCombo();
	int         ComboCount();
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
	int         _strength;
	int         _dexterity;
	int         _intelligence;
	int         _vitality;
	int         _wisdom;
	int         _power_mod;
	int         _vitality_mod;
	int         _attack_mod;
	int         _mp;
	int         _max_mp;
	int         _armor_value;
	int         _combo_count;
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
