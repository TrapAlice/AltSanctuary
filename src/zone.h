#pragma once

#include <string>

class Zone{
public:
	Zone();
	std::string     getName();
	std::string     getLevelRange();
private:
	std::string     _name;
	std::string     _level_range;
	bool            _explored;
};