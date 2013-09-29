#pragma once

#include "gamestate.h"
#include <vector>
#include <string>

enum class Conversation{
	STRANGE_ENCOUNTER,
};

enum class Graphic;

class State_Conversation : public iGameState {
public:
	State_Conversation(Conversation c);
	void Render( World *w, Renderer *r);
	void Update( Stack<iGameState*> *s, World *w, char c);
private:
	Graphic         _speaker_graphic;
	std::string     _speaker_name;
	std::vector<std::string> _text;
	unsigned int    _position;
};