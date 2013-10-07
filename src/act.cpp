#include "act.h"
#include "zone.h"

Act::Act(){
	_zones.push_back(Zone());
}

Act::~Act() = default;

Zone& Act::getZone(const int& pos){
	return _zones[pos-1];
}

void Act::setCurrentQuest(const std::string& quest){
	_current_quest = quest;
}

std::string Act::getCurrentQuest() const{ return _current_quest; }
