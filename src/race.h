#pragma once

#include <string>

enum class Race{
	HUMAN,
	SILIAN,
	KRASTE,
	FLAMMKIN,
	JOTUNNAR,
	WYSPERA,
	GOERN,
	SONITE,
	HUSKIAN,
};

std::string RACE_NAME(Race r);