#include "input.h"
#include <iostream>
#include "libtcod.hpp"
#include "dbg.h"

Input::Input(){
	_key_pressed = 0;
}

int Input::Key(){
	while(_key_pressed){
		if(TCODSystem::waitForEvent(TCOD_EVENT_KEY_RELEASE, NULL, NULL, true)){
			_key_pressed=false;
		}
	}
	TCOD_key_t key = TCODConsole::waitForKeypress(true);
	_key_pressed = true;
	return( key.c );
}