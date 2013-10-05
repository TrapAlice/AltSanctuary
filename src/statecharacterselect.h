#ifndef _STATE_CHARACTERSELECT_H
#define _STATE_CHARACTERSELECT_H

#include "gamestate.h"
#include <functional>
#include <string>

enum CURRENT_STATE{
	SelectClass,
	SelectGender,
	ClassInfo,
	SelectPersonality,
	SelectGameMode,
	SelectRaceCatagory,
	SelectRace,
	EnterName,
	BackStory,
};

enum class Class;
enum class Race;

enum RACE_CATEGORY{
	Mystical,
	Powerful,
	Steadfast,
};

class State_CharacterSelect : public iGameState{
public:
	State_CharacterSelect();
	void Render(World& w, Renderer& r);
	void Update(GameStateStack& s, World& w, const char& c);
private:
	CURRENT_STATE   _state;
	Class           _selectedClass;
	Race            _selectedRace;
	RACE_CATEGORY   _raceCategory;
	int             _selectedPersonality;
	bool            _isMale;
	std::string     _name;

	std::function<void(Renderer&)> _renderFunction;
	void            _SelectClassRender(Renderer& r);
	void            _SelectGenderRender(Renderer& r);
	void            _ClassInfoRender(Renderer& r);
	void            _SelectPersonalityRender(Renderer& r);
	void            _SelectGameModeRender(Renderer& r);
	void            _SelectRaceCatagoryRender(Renderer& r);
	void            _SelectRaceRender(Renderer& r);
	void            _EnterNameRender(Renderer& r);
	void            _BackStoryRender(Renderer& r);

	std::function<void(GameStateStack&, World&, const char&)> _updateFunction;
	void            _SelectClassUpdate(GameStateStack& s, World& w, const char& c);
	void            _SelectGenderUpdate(GameStateStack& s, World& w, const char& c);
	void            _ClassInfoUpdate(GameStateStack& s, World& w, const char& c);
	void            _SelectPersonalityUpdate(GameStateStack& s, World& w, const char& c);
	void            _SelectGameModeUpdate(GameStateStack& s, World& w, const char& c);
	void            _SelectRaceCatagoryUpdate(GameStateStack& s, World& w, const char& c);
	void            _SelectRaceUpdate(GameStateStack& s, World& w, const char& c);
	void            _EnterNameUpdate(GameStateStack& s, World& w, const char& c);
	void            _BackStoryUpdate(GameStateStack& s, World& w, const char& c);
};

#endif