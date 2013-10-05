#pragma once

#include <string>

enum class Graphic{
	MAIN_MENU,
	BARBARIAN_M,
	BARBARIAN_F,
	PALADIN_M,
	PALADIN_F,
	ASSASSIN_M,
	ASSASSIN_F,
	WIZARD_M,
	WIZARD_F,
	DRUID_M,
	DRUID_F,
	RANGER_M,
	RANGER_F,
	BLANK_FACE,
	DIANE,
	num_graphics
};

void        GRAPHIC_INIT();
std::string GRAPHIC(const Graphic& g);