#include "stategamemode.h"
#include "statecombat.h"
#include "renderer.h"
#include "character.h"
#include "skill.h"
#include "enemy.h"
#include "world.h"
#include "act.h"
#include "zone.h"

void State_GameMode::Render( World& w, Renderer& r ){
	Character& c = w.Player();
	Act *a = w.GetCurrentAct();
	r.printlns(0, "");
	r.printlns(0, "                                    ,sdPBbs.");
	r.printlns(0, "                      ,dBb.       ,d$$$$$$$$b.                .   ._, |_");
	r.printlns(0, "                     /sbbbs`.    d$P'`Y'`Y'`?$b          `-.``/  .  ` /");
	r.printlns(0, "          ,dPBb    _/   | . ,`. d'    `  '  : `b            ``. _`,   | :.");
	r.printlns(0, "         /sBDDBS. /  / /       /    |       ::. `      _|_.___``, ``/ -.;||");
	r.printlns(0, "       ./        `.   /   `   /    / `           `         ` -,--.`._|| / /");
	r.printlns(0, "      /      |  ,  ;     _,--'        |           |.      ;'   `-.`./ / |/");
	r.printlns(0, "   _/` .    /       .__/' _/          `   |`       `.            |   -|//");
	r.printlns(0, "  /   /   .  ,   /    _/' /'             |   `        `-.,__     |_    /");
	r.printlns(0, "");
	r.printlns(0, "");
	r.printlns(2, "HP: %d / %d   ATK: 67 - 80   MP: 65 / 65   GOLD: 0", c.Hp(), c.MaxHp()); //Player stats
	r.printlns(0, "");
	r.printlns(0, "+-----------------------------------------------------------------------------+");
	r.printlns(2, "Quest: Search the Grassy Fields for another Gate."); //Current quest
	r.printlns(0, "+-----------------------------------------------------------------------------+");
	r.printlns(0, "|                                 |       |                 | [R] Heal [>>>]  |");
	r.prints(2, 17, "[1] %s", a->getZone(1)->getName().c_str());
	r.prints(26, 17, "(%s)", a->getZone(1)->getLevelRange().c_str());
	r.printlns(0, "|                                 |       |                 |                 |");
	r.printlns(0, "|                                 |       |                 |                 |");
	r.printlns(0, "|                                 |       |-----------------------------------|");
	r.printlns(0, "|                                 |       |     --Saved--   | <0> Restart     |");
	r.printlns(0, "|                                 |       | <C> Character   | <P> Quit        |");
	r.printlns(0, "+-----------------------------------------------------------------------------+");


}

void State_GameMode::Update( std::stack<std::unique_ptr<iGameState>>& s, World& w, char c ){
	if(c == '1'){
		s.push(std::unique_ptr<State_Combat>(new State_Combat()));
	}
}
