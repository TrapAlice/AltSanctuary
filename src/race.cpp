#include "race.h"

std::string RACE_NAME(Race r){
	switch(r){
		case Race::HUMAN:
			return "Human";
		case Race::SILIAN:
			return "Silian";
		case Race::KRASTE:
			return "Kraste";
		case Race::FLAMMKIN:
			return "Flammkin";
		case Race::JOTUNNAR:
			return "Jotunnar";
		case Race::WYSPERA:
			return "Wyspera";
		case Race::GOERN:
			return "Goern";
		case Race::SONITE:
			return "Sonite";
		case Race::HUSKIAN:
			return "Huskian";
	}
}