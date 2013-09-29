#pragma once

#include <string>

enum class Class{
	BARBARIAN,
	PALADIN,
	ASSASSIN,
	WIZARD,
	DRUID,
	RANGER,
	NOCLASS,
};

std::string CLASS_NAME(Class c);
std::string CLASS_INFO(Class c);
std::string CLASS_PERSONALITY(Class c);
std::string CLASS_GRAPHIC(Class c, bool isMale);
