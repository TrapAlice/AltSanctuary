#include "zone.h"

Zone::Zone(){
	_explored    = false;
	_name        = "-> Grassy Fields";
	_level_range = "01-05";
}

Zone::~Zone() = default;

std::string Zone::getName() const{ return _name; }

std::string Zone::getLevelRange() const{
	if( !_explored ){
		return "--?--";
	}
	return _level_range;
}
