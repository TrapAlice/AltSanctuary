#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include <stack>
#include <memory>

class Renderer;
class World;

class iGameState{
public:
	virtual ~iGameState(){};
	virtual void Render( World& w, Renderer& r ) = 0;
	virtual void Update( std::stack<std::unique_ptr<iGameState>>& s, World& w, char c ) = 0;
};

#endif
