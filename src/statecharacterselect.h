#ifndef _STATE_CHARACTERSELECT_H
#define _STATE_CHARACTERSELECT_H

#include "gamestate.h"
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

enum CLASS_SELECTED{
	Barbarian,
	Paladin,
	Assassin,
	Wizard,
	Druid,
	Ranger,
};

enum RACE_CATEGORY{
	Mystical,
	Powerful,
	Steadfast,
};

class State_CharacterSelect : public iGameState{
public:
	State_CharacterSelect();
	~State_CharacterSelect();
	void Render( World *w, Renderer *r );
	void Update( Stack<iGameState*> *s, World *w, char c );
private:
	CURRENT_STATE  _state;
	CLASS_SELECTED _selectedClass;
	RACE_CATEGORY  _raceCategory;
	bool           _isMale;
	std::string    _name;
	void           _printBlankFace(Renderer *r);
	void           _SelectClassRender(Renderer *r);
	void           _SelectGenderRender(Renderer *r);
	void           _ClassInfoRender(Renderer *r);
	void           _SelectPersonalityRender(Renderer *r);
	void           _SelectGameModeRender(Renderer *r);
	void           _SelectRaceCatagoryRender(Renderer *r);
	void           _SelectRaceRender(Renderer *r);
	void           _EnterNameRender(Renderer *r);
	void           _BackStoryRender(Renderer *r);
};

#endif