#ifndef _GAME_H
#define _GAME_H

#include "stack.h"

class Renderer;
class World;
class Input;
class iGameState;

class Game{
public:
	Game();
	~Game();
	void Start();
	void End();
private:
	Renderer           *renderer_;
	Input              *input_;
	World              *world_;
	bool                done_;
	Stack<iGameState*> *state_stack_;
};

#endif
