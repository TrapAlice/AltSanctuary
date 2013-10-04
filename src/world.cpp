#include "world.h"
#include "game.h"
#include "character.h"
#include "act.h"
#include "zone.h"

World::World(){
	//player_ = NULL;
	//game_ = g;
	_current_act = new Act();
}

World::~World(){
	//if( player_ ) delete player_;
	if( _current_act) delete _current_act;
}

Character& World::Player(){ return *_player.get(); }

void World::SetPlayer(std::unique_ptr<Character> c){
	_player = std::move(c);
}

void World::End(){
	//game_->End();
}

Act* World::GetCurrentAct(){ return _current_act; };