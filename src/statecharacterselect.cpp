#include "statecharacterselect.h"
#include "stategamemode.h"
#include "renderer.h"
#include "character.h"
#include "world.h"

void State_CharacterSelect::Render(World *w, Renderer *r){
		r->printlns(0, "+-----------------------------------------------------------------------------+");
		r->printlns(0, "                                   _.------._");
		r->printlns(0, "                                  :          :");
		r->printlns(0, "                                 :            :");
		r->printlns(0, "                                 :            :");
		r->printlns(0, "                                 :            :");
		r->printlns(0, "                                 :            :");
		r->printlns(0, "                                 :            :");
		r->printlns(0, "                                  :          :");
		r->printlns(0, "                                   :        :");
		r->printlns(0, "                                _.:::.____.:::._");
		r->printlns(0, "                            _.::::::::::::::::::::._");
		r->printlns(0, "                          .::::::::::::::::::::::::::.");
		r->printlns(0, "+-----------------------------------------------------------------------------+");
		r->printlns(2, "Select Character:");
		r->printlns(0, "+-----------------------------------------------------------------------------+");
		r->printlns(1, "[1] Barbarian");
		r->printlns(1, "[2] Paladin");
		r->printlns(1, "[3] Assassin");
		r->printlns(1, "[4] Wizard");
		r->printlns(1, "[5] Druid");
		r->printlns(1, "[6] Ranger");
		r->printlns(0, "+-----------------------------------------------------------------------------+"); 
}

void State_CharacterSelect::Update(Stack<iGameState*> *s, World *w, char c){
	switch( c ){
		case '1':
			w->SetPlayer(new Character(CLASS_BARBARIAN));
			s->Push(new State_GameMode());
			break;
		case '2':
			w->SetPlayer(new Character(CLASS_PALADIN));
			s->Push(new State_GameMode());
			break;
		case '3':
			w->SetPlayer(new Character(CLASS_ASSASSIN));
			s->Push(new State_GameMode());
			break;
		case '4':
			w->SetPlayer(new Character(CLASS_WIZARD));
			s->Push(new State_GameMode());
			break;
		case '5':
			w->SetPlayer(new Character(CLASS_DRUID));
			s->Push(new State_GameMode());
			break;
		case '6':
			w->SetPlayer(new Character(CLASS_RANGER));
			s->Push(new State_GameMode());
			break;
		case 'a':
			w->End();
			break;
	}
}
