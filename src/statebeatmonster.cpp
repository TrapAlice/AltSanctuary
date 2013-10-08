#include "statebeatmonster.h"
#include "character.h"
#include "enemy.h"
#include "renderer.h"
#include "world.h"

State_BeatMonster::State_BeatMonster()
{
	_gold_drop = rand() % 150 + 100 + 5;
	_exp_drop  = rand() % 5 + 25 + 2;
}

State_BeatMonster::State_BeatMonster(Enemy e){
	_gold_drop = rand() % (e.getGold()/2) + e.getGold();
	_exp_drop = rand() % (e.getExp()/2) + e.getExp();
}

void State_BeatMonster::Render(World &w, Renderer& r){
	Character& c = w.Player();
	r.prints(3, 1, "NAME: %s <[%d]> [%s %s - %s] <Casual>",
		     c.Name().c_str(), c.Level(), 
		     c.getRaceName().c_str(), c.ClassName().c_str(),
		     c.getGender().c_str());
	r.printlns(3, "WEAP:");
	r.printlns(3, "ARMR:");
	r.printlns(3, "CHRM:");
	r.printlns(4, "VIT: [%d] +%d HP PP", c.Vit(), c.VitMod());
	r.printlns(4, "STR: [%d] +%d ATK PP, +%d%%%% LOH", c.Str(), c.PowerMod(), c.Str()); // LOH is life on hit
	r.printlns(4, "INT: [%d] +0.5MP PP", c.Int());
	r.printlns(4, "DEX: [%d] = %d%%%% CC", c.Dex(), 10); //Todo: cc is crit chance
	r.printlns(4, "WIS: [%d] = %d RGN", c.Wis(), c.Wis()/5); //RGN is regen
	r.printlns(5, "XP: [%d/%d] (+15%%%%)", c.getExp(), 1000);
	r.printlns(0, "");
	r.printlns(2, "HP %d/%d ATK %d/%d MP %d/%d GOLD %d",
		           c.Hp(), c.MaxHp(),
		           c.MinPower(), c.MaxPower(),
		           c.Mp(), c.MaxMp(),
		           c.getGold());
	r.prints(0, 21, "+-----------------------------------------------------------------------------+");
	r.printlns(2, "You have slain the Enemy!    [ + %d EXP ] [ + %d GOLD ]", _exp_drop, _gold_drop);
	r.printlns(0, "+-----------------------------------------------------------------------------+");
}

void State_BeatMonster::Update(GameStateStack& s, World& w, const char& c){
	Character& character = w.Player();
	w.RestoreHealingCharge();
	character.IncreaseGold(_gold_drop);
	character.IncreaseExp(_exp_drop);
	s.pop();
}