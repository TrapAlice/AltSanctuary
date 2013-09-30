#pragma once

#include <string>

class Zone;

class Act{
public:
	Act();
	Zone*           getZone(int pos);
	void            setCurrentQuest(std::string quest);
	std::string     getCurrentQuest();
private:
	Zone            **_zones;
	std::string     _current_quest;
};