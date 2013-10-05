#ifndef _GAME_H
#define _GAME_H

#include <memory>
#include <stack>

class iGameState;
class Input;
class Renderer;
class World;

class Game{
public:
	Game(std::unique_ptr<Renderer>& renderer, std::unique_ptr<Input>& input);
	~Game();
	void            Start();
	void            End();
private:
	std::unique_ptr<Renderer> _renderer;
	std::unique_ptr<World> _world;
	std::unique_ptr<Input> _input;
	bool            _done;
	std::stack<std::unique_ptr<iGameState>> _state_stack;
};

#endif
