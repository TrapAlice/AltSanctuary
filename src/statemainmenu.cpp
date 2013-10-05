#include "statemainmenu.h"
#include "graphic.h"
#include "renderer.h"
#include "statecharacterselect.h"
#include "world.h"

void State_MainMenu::Render( World& w, Renderer& r ){
	r.printlns(0,   "+-----------------------------------------------------------------------------+");
	r.printlns(25,  "AltSanctuary - Beta v0.0.01");
	r.printlns(0,   "+-----------------------------------------------------------------------------+");
	r.prints(0,  3, GRAPHIC(Graphic::MAIN_MENU)); 
	r.prints(0, 14,   "+-----------------------------------------------------------------------------+");
	r.printlns(0,   "");
	r.printlns(0,   "+-----------------------------------------------------------------------------+");
	r.printlns(1,   "[1] New Game"); //Campaign if save file exists
	r.printlns(1,   "[2] Continue");
	r.printlns(1,   "[3] Options");
	r.printlns(1,   "[4] Credits");
	r.printlns(0,   "");
	r.printlns(1,   "[X] Exit");
	r.printlns(0,   "+-----------------------------------------------------------------------------+");
}

void State_MainMenu::Update( GameStateStack& s, World& w, const char& c ){
	switch( c ){
		case '1':
			s.push(new_state(CharacterSelect));
			break;
		case 'x':
			s.pop();
			break;
	}
}