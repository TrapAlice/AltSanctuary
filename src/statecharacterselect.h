#ifndef _STATE_CHARACTERSELECT_H
#define _STATE_CHARACTERSELECT_H

#include "gamestate.h"
#include <string>
#include <functional>

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
	void Render( World& w, Renderer& r );
	void Update( std::stack<std::unique_ptr<iGameState>>& s, World& w, char c );
private:
	CURRENT_STATE  _state;
	Class          _selectedClass;
	Race           _selectedRace;
	RACE_CATEGORY  _raceCategory;
	int            _selectedPersonality;
	bool           _isMale;
	std::string    _name;

	std::function<void(Renderer&)> _renderFunction;
	void           _SelectClassRender(Renderer& r);
	void           _SelectGenderRender(Renderer& r);
	void           _ClassInfoRender(Renderer& r);
	void           _SelectPersonalityRender(Renderer& r);
	void           _SelectGameModeRender(Renderer& r);
	void           _SelectRaceCatagoryRender(Renderer& r);
	void           _SelectRaceRender(Renderer& r);
	void           _EnterNameRender(Renderer& r);
	void           _BackStoryRender(Renderer& r);

	std::function<void(std::stack<std::unique_ptr<iGameState>>&, World&, char)> _updateFunction;
	void           _SelectClassUpdate(std::stack<std::unique_ptr<iGameState>>& s, World& w, char c);
	void           _SelectGenderUpdate(std::stack<std::unique_ptr<iGameState>>& s, World& w, char c);
	void           _ClassInfoUpdate(std::stack<std::unique_ptr<iGameState>>& s, World& w, char c);
	void           _SelectPersonalityUpdate(std::stack<std::unique_ptr<iGameState>>& s, World& w, char c);
	void           _SelectGameModeUpdate(std::stack<std::unique_ptr<iGameState>>& s, World& w, char c);
	void           _SelectRaceCatagoryUpdate(std::stack<std::unique_ptr<iGameState>>& s, World& w, char c);
	void           _SelectRaceUpdate(std::stack<std::unique_ptr<iGameState>>& s, World& w, char c);
	void           _EnterNameUpdate(std::stack<std::unique_ptr<iGameState>>& s, World& w, char c);
	void           _BackStoryUpdate(std::stack<std::unique_ptr<iGameState>>& s, World& w, char c);
};

#endif