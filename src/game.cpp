#include "game.h"

#include "input.h"
#include "gamestate.h"
	#include "statemainmenu.h"
#include "renderer.h"
#include "world.h"

using std::stack;
using std::shared_ptr;

Game::Game(std::unique_ptr<Renderer>& renderer, std::unique_ptr<World>& world, std::unique_ptr<Input>& input)
	: _done(false)
{
	_renderer   = std::move(renderer);
	_world      = std::move(world);
	_input      = std::move(input);
}

Game::~Game()
{}

void Game::Start(){
	char selection;
	_state_stack.push(std::unique_ptr<State_MainMenu>(new State_MainMenu));
	while( !_done && !_state_stack.empty() ){
		iGameState* current_state = _state_stack.top().get();
		current_state->Render(*_world.get(), *_renderer.get());
		_renderer->Flush();
		selection = _input->Key();
		if( selection == '#' || _renderer->isClosed()) _done = true;
		current_state->Update(_state_stack, *_world.get(), selection);
	}
	//_state_stack.clear();
}

void Game::End(){
	_done = true;
}