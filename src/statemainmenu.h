#ifndef _STATE_MAINMENU_H
#define _STATE_MAINMENU_H

#include "gamestate.h"

class State_MainMenu : public iGameState{
public:
	void Render( World& w, Renderer& r );
	void Update( std::stack<std::unique_ptr<iGameState>>& s, World& w, char c );
};

#endif
