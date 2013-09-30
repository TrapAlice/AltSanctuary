#include "statecombat.h"
#include "renderer.h"
#include "character.h"
#include "skill.h"
#include "enemy.h"
#include "world.h"
#include "dbg.h"

State_Combat::State_Combat(){
	skill_offset_    = 0;
	player_position_ = 0;
	repositioning_   = false;
	current_enemy_   = new Enemy("Test", 200, 1, 5);
}

State_Combat::State_Combat(Enemy *enemy){
	skill_offset_    = 0;
	player_position_ = 0;
	repositioning_   = false;
	current_enemy_   = enemy;
}

void State_Combat::Render(World *w, Renderer *r){
	Character *c = w->Player();
	r->prints(0, 1, "> Monster taunt");
	r->prints(2, 3, "HP: %d / %d", c->Hp(), c->MaxHp()); //Monster's stats
	r->prints(18,3, "ATK: %d - %d", c->MinPower(), c->MaxPower());
	r->prints(4, 4, "[::::::::::] [-]");
	r->prints(0, 7, "> You are ready for battle.");
	r->prints(2, 9, "HP: %d / %d", c->Hp(), c->MaxHp());
	r->prints(18,9, "ATK: %d - %d", c->MinPower(), c->MaxPower());
	r->prints(35,9, "MP: %d / %d", c->Mp(), c->MaxMp());
	r->prints(4, 10, "[::::::::::::::::::::]");
	r->prints(0, 12, "+-----------------------------------------------------------------------------+");
	r->printlns(1, "[1] Cleave           (Starter---)     ( No MP, 50%%%% ATK + 87 DMG)");
	r->printlns(1, "[2] Whirlwind        (Starter---)     (+10 MP, 2X ATK, -174 HP, 73%%%% HIT)");
	r->printlns(1, "[3] Frenzy           (Starter---)     (-10 MP, 20%%%% ATK)");
	r->printlns(1, "[4] Heal             (---Heal---)     (-20 MP, Restore 435 HP)");
	r->printlns(1, "[S] Swap Skillset    (----------)     (Unlocked at Level ");
	r->printlns(0, "");
	r->printlns(1, "[Q] Reflect Damage   (----------)     (Unlocked at Level 10)");
	r->printlns(1, "[W] Activate Shield  (----------)     (Unlocked at Level 15)");
	r->printlns(1, "[E] Adrenal Smash    (----------)     (Unlocked at Level 20)");
	r->printlns(66, "[5] Run (20%%%%)");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
}

/*

> Skeleton probably wants to wear your skull as a necklace.

  HP: 194 / 194   ATK: 30 - 52
    [::::::::::] [-]


> You are ready for battle.

  HP: 870 / 870   ATK: 67 - 80   MP: 65 / 65
    [::::::::::::::::::::]

+-----------------------------------------------------------------------------+
 [1] Cleave           (Starter---)     ( No MP, 50% ATK + 87 DMG)
 [2] Whirlwind        (Starter---)     (+10 MP, 2X ATK, -174 HP, 73% HIT)
 [3] Frenzy           (Starter---)     (-10 MP, 20% ATK)
 [4] Heal             (---Heal---)     (-20 MP, Restore 435 HP)
 [S] Swap Skillset    (----------)     (Unlocked at Level 5)

 [Q] Reflect Damage   (----------)     (Unlocked at Level 10)
 [W] Activate Shield  (----------)     (Unlocked at Level 15)
 [E] Adrenal Smash    (----------)     (Unlocked at Level 20)
                                                                 [5] Run (20%)
+-----------------------------------------------------------------------------+
*/

void State_Combat::Update(Stack<iGameState*> *s, World *w, char c){
	bool action_taken = false;
		if( !repositioning_ ){
		switch( c ){
			case 'q':
			case 'Q':
				s->Pop();
				break;
			case 'r':
			case 'R':
				repositioning_ = true;
				break;
			case 'e':
			case 'E':
				skill_offset_ ^= 1;
				break;
			case 'w':
			case 'W':
				break;		
			case '1':
			case '2':
			case '3':
			case '4':
				//Skill* selected_skill = w->Player()->GetSkill(c-'1'+skill_offset_*4);
				/*if(w->Player()->Initiative() >= 0-selected_skill->Init()){
					_PlayerAttack(w, selected_skill);
					action_taken = true;
				}*/
				break;
		}
	} else {
		switch( c ){
			case 'q':
			case 'Q':
				if( player_position_ != 0){
					player_position_--;
					action_taken = true;
				}
				repositioning_ = false;
				break;
			case 'w':
			case 'W':
				repositioning_ = false;
				break;
			case 'e':
			case 'E':
				if( player_position_ != 2){ 
					player_position_++;
					action_taken = true;
				}
				repositioning_ = false;
				break;
		}
	}
	if( action_taken ){
			current_enemy_->CycleConditions(1, 0, w->Player());
			double damage = 25;
			current_enemy_->CycleConditions(2, &damage, w->Player());
			w->Player()->TakeDamage(damage);
			w->Player()->CycleConditions(1, 0, current_enemy_);
		}
		//if( current_enemy_->Hp() <= 0 ){
		//	w->Player()->ClearConditions();
		//	w->ChangeState(STATE_GAMEMODE);
		//}
}

void State_Combat::_PlayerAttack(World *w, Skill *skill){
	double damage = skill->Attack(w->Player(), current_enemy_);
	w->Player()->CycleConditions(2, &damage, current_enemy_);
	current_enemy_->TakeDamage(damage);
}

State_Combat::~State_Combat(){
	delete current_enemy_;
}