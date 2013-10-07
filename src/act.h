#pragma once

#include <memory>
#include <string>
#include <vector>

class Zone;

class Act{
public:
	Act();
	~Act();
	Zone&           getZone(const int& pos);
	void            setCurrentQuest(const std::string& quest);
	std::string     getCurrentQuest() const;
private:
	std::vector<Zone> _zones;
	std::string     _current_quest;
};