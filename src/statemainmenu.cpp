#include "statemainmenu.h"
#include "statecharacterselect.h"
#include "renderer.h"
#include "world.h"

void State_MainMenu::Render(World *w, Renderer *r){
	r->printlns(0,   "+-----------------------------------------------------------------------------+");
	r->printlns(30,  "AltSanctuary - Beta v0.0");
	r->printlns(0,   "+-----------------------------------------------------------------------------+");
	r->prints(0,  4, "                            ,sdPBbs.");
 	r->printlns(0,   "                          ,d$$$$$$$$b.               v .   ._, |_  .,"); 
	r->printlns(0,   "                         d$P'`Y'`Y'`?$b           `-.``/  .  ` /   |'_"); 
	r->printlns(0,   "                        d'    `  '  : `b              ``. _`, y | :. "); 
	r->printlns(0,   "                       /    |       ::. `       _|_.___``, ``/ -.;||"); 
	r->printlns(0,   "                      /    / `           `        `7-,--.`._|| / / ,"); 
	r->printlns(0,   "                 _,--'        |           |.      ;'     `-.`./ / |/_.'"); 
	r->printlns(0,   "                /' _/          `   |`       `.             |    |//"); 
	r->printlns(0,   "              _/' /'             |   `        `-.__        |_    /"); 
	r->printlns(0,   "           __/'       ,-'    /    |    |     `      `--..._|-   |"); 
	r->printlns(0,   "          /'          /      |    / `     `     `-.        |   =|"); 
	r->printlns(0,   "         /    /;;,,__-'      /   /    `    `              / , .  |");
	r->printlns(0,   "+-----------------------------------------------------------------------------+");
	r->printlns(0,   "+-----------------------------------------------------------------------------+");
	r->printlns(1,   "[1] Campaign");
	r->printlns(1,   "[2] Challenges");
	r->printlns(1,   "[3] Credits");
	r->printlns(1,   "[4] Exit");
	r->printlns(0,   "+-----------------------------------------------------------------------------+");
}

void State_MainMenu::Update(Stack<iGameState*> *s, World *w, char c){
	switch( c ){
		case '1':
			s->Push(new State_CharacterSelect());
			break;
		case '4':
			w->End();
			break;
	}
}