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
	r->printlns(0, "");
	r->printlns(0, "                                    ,sdPBbs.");
	r->printlns(0, "                      ,dBb.       ,d$$$$$$$$b.                .   ._, |_");
	r->printlns(0, "                     /sbbbs`.    d$P'`Y'`Y'`?$b          `-.``/  .  ` /");
	r->printlns(0, "          ,dPBb    _/   | . ,`. d'    `  '  : `b            ``. _`,   | :.");
	r->printlns(0, "         /sBDDBS. /  / /       /    |       ::. `      _|_.___``, ``/ -.;||");
	r->printlns(0, "       ./        `.   /   `   /    / `           `         ` -,--.`._|| / /");
	r->printlns(0, "      /      |  ,  ;     _,--'        |           |.      ;'   `-.`./ / |/");
	r->printlns(0, "   _/` .    /       .__/' _/          `   |`       `.            |   -|//");
	r->printlns(0, "  /   /   .  ,   /    _/' /'             |   `        `-.,__     |_    /");
	r->printlns(0, "");
	r->printlns(0, "");
	r->printlns(2, "HP: 870 / 870   ATK: 67 - 80   MP: 65 / 65   GOLD: 0"); //Player stats
	r->printlns(0, "");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(2, "Quest: Search the Grassy Fields for another Gate."); //Current quest
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(0, "| [1] -> Grassy Fields    (01-05) |       |                 | [R] Heal [>>>]  |");
	r->printlns(0, "|                                 |       |                 |                 |");
	r->printlns(0, "|                                 |       |                 |                 |");
	r->printlns(0, "|                                 |       |-----------------------------------|");
	r->printlns(0, "|                                 |       |     --Saved--   | <0> Restart     |");
	r->printlns(0, "|                                 |       | <C> Character   | <P> Quit        |");
	r->printlns(0, "+-----------------------------------------------------------------------------+");


}

void State_GameMode::Update(Stack<iGameState*> *s, World *w, char c){

}
