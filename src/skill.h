#ifndef _SKILL_H
#define _SKILL_H

#include "skillid.h"
#include <string>

#define SCALE_STR 1<<0
#define SCALE_DEX 1<<1
#define SCALE_INT 1<<2
#define SCALE_WIS 1<<3
#define SCALE_VIT 1<<4
#define SCALE_TGH 1<<5

class Character;
class Enemy;

enum class SKILL;
enum class SkillType{
	STARTER,
	LINKER,
	FINISHER,
	HEAL,
	ULTIMATE,
	REPOSITION,
};

class Skill{
public:
	static Skill    CreateSkill(SKILL id);
	Skill(std::string name, SkillType type, void (*skill_function)(int&, Character&, Enemy&), std::string(*summary_function)(const Character&));
	Skill();
	std::string     Name();
	std::string     GetSummary(const Character& character);
	std::string     Type();
	int             Attack(Character &character, Enemy &enemy);
private:
	std::string     _name;
	std::string    (*_summary_function)(const Character&); //To be replaced with std::functions
	void           (*_skill_function)(int&, Character&, Enemy&);
	SkillType       _type;

	double          init_;
	double          damage_;
	double          atk_mod_;	
	int             scale_stats_;
	int             scale_value_;
	
};

#endif
