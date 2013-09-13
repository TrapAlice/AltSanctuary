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
	Enemy *m = current_enemy_;
	//Frames
	r->prints(0, 6, "+--------------------------------------+--------------------------------------+");
	r->prints(0, 13, "+--------------------------------------+--------------------------------------+");
	r->prints(39, 7, "|");
	r->prints(39, 8, "|");
	r->prints(39, 9, "|");
	r->prints(39, 10, "|");
	r->prints(39, 11, "|");
	r->prints(39, 12, "|");
	r->prints(0, 22, "+-----------------------------------------------------------------------------+");

	//Player's stats
	r->prints(1, 7, "You");
	r->prints(1, 8, "ini");
	r->prints(5, 8, "%0.1f", c->Initiative());
	r->prints(10, 7, "%d / %d", c->Hp(), c->MaxHp());

	//Enemy's stats
	r->prints(41, 7, "%s", m->Name().c_str());
	r->prints(51, 7, "%d / %d", m->Hp(), m->MaxHp());

	if( !repositioning_ ){
		//Player's Abilities
		r->prints(1, 15, "[R] Reposition");
		r->prints(40, 15, "[E] Swap skill set (free action)");
		r->prints(40, 16, "[Q] Run (100 chance)");

		//Player's Skills
		
		for( int x = 0; x < 4; ++x ){
			r->prints(1, 18+x, "[%d] %s",x+1, c->SkillSummary(x+skill_offset_*4).c_str());
		}
	} else {
		if( player_position_!= 0 ) r->prints(1, 15, "[Q] Move closer"); //I want to hit it with my sword
		r->prints(1, 16, "[W] Stay");
		if( player_position_!= 2 ) r->prints(1, 17, "[E] Move away");
	}



}

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
				Skill* selected_skill = w->Player()->GetSkill(c-'1'+skill_offset_*4);
				if(w->Player()->Initiative() >= 0-selected_skill->Init()){
					_PlayerAttack(w, selected_skill);
					action_taken = true;
				}
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