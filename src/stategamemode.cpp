#include "stategamemode.h"
#include "act.h"
#include "character.h"
#include "enemy.h"
#include "renderer.h"
#include "skill.h"
#include "statecombat.h"
#include "world.h"
#include "zone.h"

void State_GameMode::Render( World& w, Renderer& r ){
	Character& c = w.Player();
	Act a = w.GetCurrentAct();
	int healing_charges = w.GetHealingCharges();
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
	r.printlns(2, "HP: %d / %d   ATK: %d - %d   MP: %d / %d   GOLD: %d", 
	           c.Hp(), c.MaxHp(),
	           c.MinPower(), c.MaxPower(),
	           c.Mp(), c.MaxMp(),
	           c.getGold()); //Player stats
	r.printlns(0, "");
	r.printlns(0, "+-----------------------------------------------------------------------------+");
	r.printlns(2, "Quest: Search the Grassy Fields for another Gate."); //Current quest
	r.printlns(0, "+-----------------------------------------------------------------------------+");
	r.printlns(0, "|                                 |       |                 |                 |");
	r.printlns(0, "|                                 |       |                 |                 |");
	r.printlns(0, "|                                 |       |                 |                 |");
	r.printlns(0, "|                                 |       |-----------------------------------|");
	r.printlns(0, "|                                 |       |     --Saved--   | <0> Restart     |");
	r.printlns(0, "|                                 |       | <C> Character   | <P> Quit        |");
	r.printlns(0, "+-----------------------------------------------------------------------------+");

	r.prints(2, 17, "[1] %s", a.getZone(1).getName().c_str());
	r.prints(26, 17, "(%s)", a.getZone(1).getLevelRange().c_str());
	r.prints(62, 17, "[R] Heal [%s%s%s]"
		              , healing_charges>0 ? ">" : " "
		              , healing_charges>1 ? ">" : " "
		              , healing_charges>2 ? ">" : " ");


}

void State_GameMode::Update( GameStateStack& s, World& w, const char& c ){
	switch( c )
	{
		case '1':
			s.push(new_state(Combat, std::unique_ptr<Enemy>(new Enemy("Test", 200, 50, 500, 500))));
			break;
		case 'r':
		case 'R':
			w.UseHealingCharge();
			break;
	}
}
