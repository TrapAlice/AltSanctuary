#include "game.h"
#include "input.h"
#include "gamestate.h"
#include "renderer.h"
#include "statemainmenu.h"
#include "world.h"

Game::Game(std::unique_ptr<Renderer>& renderer, std::unique_ptr<Input>& input)
	: _renderer(std::move(renderer))
	, _input(std::move(input))
	, _done(false)
{
	_world = std::unique_ptr<World>(new World);
}

Game::~Game()
{}

void Game::Start(){
	char selection;
	_state_stack.push(new_state(MainMenu));
	while( !_done && !_state_stack.empty() ){
		iGameState* current_state = _state_stack.top().get();
		current_state->Render(*_world.get(), *_renderer.get());
		_renderer->Flush();
		selection = _input->Key();
		if( selection == '#' || _renderer->isClosed()) _done = true;
		current_state->Update(_state_stack, *_world.get(), selection);
	}
}

void Game::End(){
	_done = true;
}