#pragma once

#include <string>

enum class Class{
	BARBARIAN,
	PALADIN,
	ASSASSIN,
	WIZARD,
	DRUID,
	RANGER,
};

std::string CLASS_INFO(Class c);
