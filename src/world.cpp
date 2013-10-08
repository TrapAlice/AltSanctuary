#include "world.h"
#include "act.h"
#include "character.h"

World::World()
{
	_current_act = std::unique_ptr<Act>(new Act());
	_healing_charge = 3;
}

World::~World() = default;

Character& World::Player() const { return *_player.get(); }

void World::SetPlayer(std::unique_ptr<Character>& c){
	_player = std::move(c);
}

Act& World::GetCurrentAct() const { return *_current_act.get(); }

void World::UseHealingCharge()
{
	if( _healing_charge ){
		--_healing_charge;
	} else {
		_player->SpendGold(250);
	}
	_player->FullyHeal();
}

void World::RestoreHealingCharge()
{
	_healing_charge = _healing_charge >= 3 ? 3 : ++_healing_charge;
}

int World::GetHealingCharges() const { return _healing_charge; }