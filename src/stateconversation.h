#pragma once

#include "gamestate.h"
#include <string>
#include <vector>

enum class Conversation{
	STRANGE_ENCOUNTER,
};

enum class Graphic;

class State_Conversation : public iGameState {
public:
	State_Conversation(Conversation c);
	void            Render( World& w, Renderer& r );
	void            Update( GameStateStack& s, World& w, const char& c );
private:
	Graphic         _speaker_graphic;
	std::string     _speaker_name;
	std::vector<std::string> _text;
	unsigned int    _position;
};