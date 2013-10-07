#pragma once

#include <string>

class Zone{
public:
	Zone();
	~Zone();
	std::string     getName() const;
	std::string     getLevelRange() const;
private:
	std::string     _name;
	std::string     _level_range;
	bool            _explored;
};