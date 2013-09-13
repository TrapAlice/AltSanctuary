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

class Skill{
public:
	static Skill* CreateSkill(int skill_id);
	Skill(std::string name, double init, double damage, double atk_mod, int scale_stats, double scale_value, void (*skill_function)(int*, Character*, Enemy*));
	std::string Name();
	double      Init();
	double      Damage();
	double      AtkMod();
	std::string GetSummary();
	int         Attack(Character *character, Enemy *enemy);
private:
	std::string  name_;
	double       init_;
	double       damage_;
	double       atk_mod_;	
	int          scale_stats_;
	int          scale_value_;
	void        (*skill_function_)(int*, Character*, Enemy*);
};

#endif
