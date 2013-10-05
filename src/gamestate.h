#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include <memory>
#include <stack>

class Renderer;
class World;

class iGameState;
typedef std::stack<std::unique_ptr<iGameState>> GameStateStack;

#define new_state(state, ...) std::unique_ptr<State_##state>(new State_##state(__VA_ARGS__))

class iGameState{
public:
	virtual ~iGameState(){};
	virtual void    Render( World& w, Renderer& r ) = 0;
	virtual void    Update( GameStateStack& s, World& w, const char& c ) = 0;
};

#endif
