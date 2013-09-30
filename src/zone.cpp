#include "zone.h"

Zone::Zone(){
	_explored    = false;
	_name        = "-> Grassy Fields";
	_level_range = "01-05";
}

std::string Zone::getName(){ return _name; }

std::string Zone::getLevelRange(){
	if( !_explored ){
		return "--?--";
	}
	return _level_range;
}
