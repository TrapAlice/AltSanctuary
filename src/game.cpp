#include "game.h"
#include "world.h"
#include "gamestate.h"
#include "input.h"
#include "statemainmenu.h"

#include "renderer.h"

Game::Game(){
	renderer_    = new Renderer();
	world_       = new World(this);
	input_       = new Input();
	done_        = false;
	state_stack_ = new Stack<iGameState*>;
}

Game::~Game(){
	if( renderer_ ) delete renderer_;
	if( world_ )    delete world_;
	if( input_ )    delete input_;
}

void Game::Start(){
	char selection;
	state_stack_->Push(new State_MainMenu());
	while( !done_ ){
		state_stack_->Top()->Render(world_, renderer_);
		renderer_->Flush();
		selection = input_->Key();
		if( selection == '#' || renderer_->isClosed()) done_ = true;
		state_stack_->Top()->Update(state_stack_, world_, selection);
	}
	state_stack_->Clear();
}

void Game::End(){
	done_ = true;
}