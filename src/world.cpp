#include "world.h"
#include "game.h"
#include "character.h"
#include "act.h"
#include "zone.h"

World::World(Game* g){
	player_ = NULL;
	game_ = g;
	_current_act = new Act();
}

World::~World(){
	if( player_ ) delete player_;
	if( _current_act) delete _current_act;
}

Character* World::Player(){ return( player_ ); }

void World::SetPlayer(Character *c){
	player_ = c;
}

void World::End(){
	game_->End();
}

Act* World::GetCurrentAct(){ return _current_act; };