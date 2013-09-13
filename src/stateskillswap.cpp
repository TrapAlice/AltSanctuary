#include "stateskillswap.h"
#include "renderer.h"
#include "character.h"
#include "skill.h"
#include "world.h"

State_SkillSwap::State_SkillSwap(){
	select_ = true;
}

void State_SkillSwap::Render(World *w, Renderer *r){
	Character *c = w->Player();
	if( select_ ){
		r->printlns(0, "Change Skills:");
		r->printlns(0, "+-----------------------------------------------------------------------------+");
		for( int x=0; x<8; x++ ){
			r->printlns(1,"[%d] %s", x+1, c->SkillSummary(x).c_str());
		}
	} else {
		r->printlns(0, "Select Skill:");
		r->printlns(0, "+-----------------------------------------------------------------------------+");
		for( int x=0; x<c->SkillLibrarySize(); x++ ){
			r->printlns(1,"[%d] %s", x+1, c->SkillSummary(x).c_str());
		}
	}
}

void State_SkillSwap::Update(Stack<iGameState*> *s, World *w, char c){
	if( select_ ){
		switch( c ){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
				skill_pos_ = c-'1';
				select_ = false;
				break;
			case 'a':
			case 'A':
				s->Pop();
				break;
		}
	} else {
		switch( c ){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
				w->Player()->SetSkill(skill_pos_, c-'1');
				select_ = true;
				break;
			case 'a':
			case 'A':
				select_ = true;
				break;
		}
	}
}