#include "stategamemode.h"
#include "stateinventory.h"
#include "stateskillswap.h"
#include "statecombat.h"
#include "renderer.h"
#include "character.h"
#include "skill.h"
#include "enemy.h"
#include "world.h"

void State_GameMode::Render(World *w, Renderer *r){
	Character *c = w->Player();
	r->prints(0, 0,  "+-----------------------------------------------------------------------------+");
	r->prints(1, 2,  "%s the Lvl %d %s", c->Name().c_str(), 1, c->Class().c_str());
	r->prints(1, 3,  "WEAP: Name [iLvl 0] Effect");
	r->prints(1, 4,  "ARMR: [0%]");
	r->prints(1, 5,  "ITEM: Name [+0]");
	r->prints(1, 7,  "VIT: [%0.1f]", c->Vit());
	r->prints(1, 8,  "STR: [%0.1f]", c->Str());
	r->prints(1, 9,  "INT: [%0.1f]", c->Int());
	r->prints(1, 10, "DEX: [%0.1f]", c->Dex());
	r->prints(0, 11, "+-----------------------------------------------------------------------------+");
	r->prints(0, 13, "> HP: %d/%d", c->Hp(), c->MaxHp());
	r->prints(0, 15, "+-----------------------------------------------------------------------------+");
	r->prints(1, 16, "[1] Test Fight");
	r->prints(1, 17, "[s] Change Skills");
	r->prints(1, 18, "[e] Equipment");
	r->prints(0, 22, "+-----------------------------------------------------------------------------+");

}

void State_GameMode::Update(Stack<iGameState*> *s, World *w, char c){
	switch( c ){
		case 'E':
		case 'e':
			s->Push(new State_Inventory());
			break;
		case 'S':
		case 's':
			s->Push(new State_SkillSwap());
			break;
		case '1':
			s->Push(new State_Combat());
			break;
		case '4':
			w->End();
			break;
	}
}
