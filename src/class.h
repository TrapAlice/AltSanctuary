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

std::string CLASS_NAME(const Class& c);
std::string CLASS_INFO(const Class& c);
std::string CLASS_PERSONALITY(const Class& c);
std::string CLASS_GRAPHIC(const Class& c, const bool& isMale);
