#include "world.h"
#include "act.h"
#include "character.h"

World::World()
{
	_current_act = std::unique_ptr<Act>(new Act());
}

World::~World() = default;

Character& World::Player() const { return *_player.get(); }

void World::SetPlayer(std::unique_ptr<Character>& c){
	_player = std::move(c);
}

Act& World::GetCurrentAct() const { return *_current_act.get(); };