#include "world.h"
#include "game.h"
#include "character.h"

World::World(Game* g){
	player_ = NULL;
	game_ = g;
}

World::~World(){
	if( player_ ) delete player_;
}

Character* World::Player(){ return( player_ ); }

void World::SetPlayer(Character *c){
	player_ = c;
}

void World::End(){
	game_->End();
}