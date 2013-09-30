#include "act.h"
#include "zone.h"

Act::Act(){
	_zones[0] = new Zone();
}

Zone* Act::getZone(int pos){
	return _zones[pos-1];
}

void Act::setCurrentQuest(std::string quest){
	_current_quest = quest;
}

std::string Act::getCurrentQuest(){ return _current_quest; }
