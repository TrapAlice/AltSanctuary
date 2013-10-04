#include "enemy.h"
#include "character.h"
#include "condition.h"
#include "conditionid.h"
#include "dbg.h"
#include "util.h"

#include <string>
#include <sstream>

bool isCrit(Character& c){
	return (rand() % 100 + 1 < ((1 + c.Dex() / 2)/(100 + c.Dex() / 2)) * 100);
}

int hitChance(const Character& c){
	return (int)((double)(100 + c.Dex() - 30)/(100 + c.Dex()) * 100);
}

void reposition(int& damage, Character& c, Enemy* e){
	c.RestoreMp(50);
	//c.ResetCombo();
	damage = -2;
}

std::string reposition_summary(const Character& c){
	return moon::BuildString("+50MP");
}

void barbarian_cleave(int& damage, Character& c, Enemy* e){
	c.IncreaseCombo();
	int attack_boost = c.AttackBoost();
	//Remove ensnare
	attack_boost += c.Vit() * 3;
	damage = c.PowerMulti(0.5) + attack_boost;
	if( isCrit(c) ){
		damage *= 3;
	}
	e->TakeDamage(damage);
}

std::string barbarian_cleave_summary(const Character& c){
	return moon::BuildString(" No MP, 50%%%% ATK + %d DMG", c.Vit()*3);
}

void barbarian_exbash(int& damage, Character& c, Enemy* e){
	c.IncreaseCombo();
	int attack_boost = c.AttackBoost();
	//Remove ensnare
	attack_boost += c.Vit() * 3;
	damage = c.PowerMulti(0.6) + attack_boost;
	if( isCrit(c) ){
		damage *= 3;
	}
	e->TakeDamage(damage);
}

std::string barbarian_exbash_summary(const Character& c){
	return moon::BuildString(" No MP, 60%%%% ATK + %d DMG", c.Vit()*3);
}

void barbarian_whirlwind(int& damage, Character& c, Enemy *e){
	damage = 0;
	if( rand() % 100 <= hitChance(c)){
		c.IncreaseCombo();
		int attack_boost = c.AttackBoost();
		c.RestoreMp(10);
		c.TakeDamage((double)c.Hp()*0.2);
		damage = c.PowerMulti(2) + attack_boost; 
		if( isCrit(c) ){
			damage *= 3;
		}
		e->TakeDamage(damage);
	}
}

std::string barbarian_whirlwind_summary(const Character& c){
	return moon::BuildString("+10 MP, 2X ATK, -%d Hp %d%%%% HIT",(int)((double)c.Hp()*0.2), hitChance(c));
}

void barbarian_exwhirlwind(int& damage, Character& c, Enemy *e){
	damage = 0;
	if( rand() % 100 <= hitChance(c)){
		c.IncreaseCombo();
		int attack_boost = c.AttackBoost();
		c.RestoreMp(10);
		c.TakeDamage((double)c.Hp()*0.05);
		damage = c.PowerMulti(2) + attack_boost; 
		if( isCrit(c) ){
			damage *= 3;
		}
		e->TakeDamage(damage);
	}
}

std::string barbarian_exwhirlwind_summary(const Character& c){
	return moon::BuildString("+10 MP, 2X ATK, -%d Hp %d%%%% HIT", (int)((double)c.Hp()*0.05), hitChance(c));
}

void barbarian_frenzy(int& damage, Character& c, Enemy *e){
	if( c.EnoughMp(10) ){
		c.IncreaseCombo();
		c.UseMp(10);
		int attack_boost = c.AttackBoost();
		damage = c.PowerMulti(0.2)+ attack_boost;
		if( isCrit(c) ){
			damage *= 3;
		}
		e->TakeDamage(damage);
	}
}

std::string barbarian_frenzy_summary(const Character& c){
	return moon::BuildString("-10 MP, 20%%%% ATK");
}

void barbarian_siesmicslam(int& damage, Character& c, Enemy *e){
	if( c.EnoughMp(10) ){
		c.IncreaseCombo();
		c.UseMp(10);
		int attack_boost = c.AttackBoost();
		damage = c.PowerMulti(1.5)+ attack_boost;
		if( isCrit(c) ){
			damage *= 3;
		}
		e->TakeDamage(damage);
	}
}

std::string barbarian_siesmicslam_summary(const Character& c){
	return moon::BuildString("-10 MP, 150%%%% ATK");
}

void finalblow(int& damage, Character& c, Enemy *e){
	if( c.EnoughMp(20) ){
		c.IncreaseCombo();
		c.UseMp(20);
		int attack_boost = c.AttackBoost();
		damage = c.PowerMulti(1.7)+ attack_boost;
		if( isCrit(c) ){
			damage *= 3;
		}
		e->TakeDamage(damage);
	}
}

std::string finalblow_summary(const Character& c){
	return moon::BuildString("-20 MP, 170%%%% ATK");
}
