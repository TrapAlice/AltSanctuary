#pragma once

#include "entity.h"
#include <string>
#include <vector>

enum class Class;
enum class Race;
class Skill;

class Character : public Entity{
public:
	Character(const Class& class_type, const Race& race, const std::string& name, const int& personality, const bool& is_male);
	~Character();
	std::string     ClassName() const;
	Race            getRace() const;
	std::string     getRaceName() const;
	std::string     getGender() const;
	int             Str() const;
	int             PowerMod() const;
	int             Dex() const;
	int             Int() const;
	int             Vit() const;
	int             VitMod() const;
	int             Wis() const;
	int             Power() const;
	int             PowerMulti(const double& multipler) const;
	int             Mp() const;
	int             MaxMp() const;
	int             Level() const;
	bool            EnoughMp(const int& amount) const;
	void            UseMp(const int& amount);
	void            RestoreMp(const int& amount);
	void            IncreaseCombo();
	void            ResetCombo();
	int             ComboCount() const;
	void            AddSkill(const Skill skill);
	const Skill&    GetSkill(const int& pos) const;
	int             SkillLibrarySize() const;
	int             getGold() const;
	void            IncreaseGold(int amount);
private:
	Class           _class;
	Race            _race;
	std::string     _name;
	int             _strength;
	int             _dexterity;
	int             _intelligence;
	int             _vitality;
	int             _wisdom;
	int             _power_mod;
	int             _vitality_mod;
	int             _attack_mod;
	int             _mp;
	int             _max_mp;
	int             _armor_value;
	int             _combo_count;
	bool            _is_male;
	int             _gold;
	std::vector<Skill> _skill_library;
	
	void _BarbarianInit(const int& personality);
	void _PaladinInit(const int& personality);
	void _AssassinInit(const int& personality);
	void _WizardInit(const int& personality);
	void _RangerInit(const int& personality);
	void _DruidInit(const int& personality);
};
