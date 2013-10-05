#include "statecombat.h"
#include "character.h"
#include "dbg.h"
#include "enemy.h"
#include "renderer.h"
#include "skill.h"
#include "world.h"


State_Combat::State_Combat(){
	skill_offset_    = 0;
	player_position_ = 0;
	current_enemy_   = new Enemy("Test", 200, 1, 5);
	memset(_used_skill, 0, 3);
	_heals_used = 0;
}

State_Combat::State_Combat(Enemy *enemy){
	skill_offset_    = 0;
	player_position_ = 0;
	current_enemy_   = enemy;
}

void State_Combat::Render(World& w, Renderer& r){
	Character c = w.Player();
	Enemy *e = current_enemy_;
	Skill s;
	r.prints(0, 1, "> Monster taunt");
	r.prints(2, 3, "HP: %d / %d", e->Hp(), e->MaxHp()); //Monster's stats
	r.prints(18,3, "ATK: %d - %d", e->MinPower(), e->MaxPower());
	//r.prints(4, 4, "[::::::::::] [-]");
	r.prints(0, 7, "> You are ready for battle.");
	r.prints(2, 9, "HP: %d / %d", c.Hp(), c.MaxHp());
	r.prints(18,9, "ATK: %d - %d", c.MinPower(), c.MaxPower());
	r.prints(35,9, "MP: %d / %d", c.Mp(), c.MaxMp());
	//r.prints(4, 10, "[::::::::::::::::::::]");
	r.prints(0, 12, "+-----------------------------------------------------------------------------+");

	Skill a1 = _Skill1(c);
	r.prints(1, 13, "[1] %s", a1.Name().c_str());
	r.prints(22, 13,"%s", a1.Type().c_str());
	r.prints(39, 13,"(%s)", a1.GetSummary(c).c_str());

	Skill a2 = _Skill2(c);
	r.prints(1, 14, "[2] %s", a2.Name().c_str());
	r.prints(22, 14,"%s", a2.Type().c_str());
	r.prints(39, 14,"(%s)", a2.GetSummary(c).c_str());

	Skill a3 = _Skill3(c);
	r.prints(1, 15, "[3] %s", a3.Name().c_str());
	r.prints(22, 15,"%s", a3.Type().c_str());
	r.prints(39, 15,"(%s)", a3.GetSummary(c).c_str());
	
	r.printlns(1, "[4] Heal             (---Heal---)     (-20 MP, Restore %d HP)", _HealValue(c));
	r.printlns(1, "[S] Swap Skillset    (----------)     (Unlocked at Level ");
	r.printlns(0, "");
	r.printlns(1, "[Q] Reflect Damage   (----------)     (Unlocked at Level 10)");
	r.printlns(1, "[W] Activate Shield  (----------)     (Unlocked at Level 15)");
	r.printlns(1, "[E] Adrenal Smash    (----------)     (Unlocked at Level 20)");
	r.printlns(66, "[5] Run (20%%%%)");
	r.printlns(0, "+-----------------------------------------------------------------------------+");
}

void State_Combat::Update( GameStateStack& s, World& w, const char& c ){
	Character character = w.Player();
	int damage;
	switch( c ){
		case '1':{
			Skill a = _Skill1(character);
			damage = a.Attack(w.Player(), current_enemy_);
			_used_skill[0] = true;
			break;
		}
		case '2':{
			Skill a = _Skill2(character);
			damage = a.Attack(w.Player(), current_enemy_);
			_used_skill[1] = true;
			break;
		}
		case '3':{
			Skill a = _Skill3(character);
			damage = a.Attack(w.Player(), current_enemy_);
			if( _used_skill[0] && _used_skill[1] && _used_skill[2] ){
				memset(_used_skill, 0, 3);
				break;
			}
			_used_skill[2] = true;
			break;
		}
		case '4':
			_Heal(character);
			break;
		default:
			return;
	}
	log_info("You dealt %d damage", damage);
}

void State_Combat::_PlayerAttack(World &w, Skill &skill){
	double damage = skill.Attack(w.Player(), current_enemy_);
	//zw.Player().CycleConditions(2, &damage, current_enemy_);
	current_enemy_->TakeDamage(damage);
}

int State_Combat::_HealValue(Character& c){
	return (500 + 25 * c.Level()) * (1 - (double)_heals_used/(_heals_used+20)) * (1 + (double)c.Int()/100);
}

void State_Combat::_Heal(Character& c){
	if( c.EnoughMp(20) ){
		c.ResetCombo();
		int heal = _HealValue(c);
		++_heals_used;
		c.UseMp(20);
		c.TakeDamage(-heal);
	}
}

const Skill& State_Combat::_Skill1(Character c){
	return _used_skill[0]? c.GetSkill(0) : _used_skill[1] || _used_skill[2]? c.GetSkill(4) : c.GetSkill(1);
}

const Skill& State_Combat::_Skill2(Character c){
	return _used_skill[1]? c.GetSkill(0) : _used_skill[0] || _used_skill[2]? c.GetSkill(5) : c.GetSkill(2);
}

const Skill& State_Combat::_Skill3(Character c){
	return _used_skill[2]? _used_skill[0] && _used_skill[1]? c.GetSkill(7) : c.GetSkill(0) : _used_skill[1] || _used_skill[0]? c.GetSkill(6) : c.GetSkill(3);
}


State_Combat::~State_Combat(){
	delete current_enemy_;
}