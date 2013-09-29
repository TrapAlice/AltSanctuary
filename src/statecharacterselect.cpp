#include "statecharacterselect.h"
#include "stategamemode.h"
#include "renderer.h"
#include "character.h"
#include "world.h"
#include "dbg.h"
#include "class.h"
#include "race.h"
#include "backstory.h"

#define STATE_CHANGE(state) _renderFunction = std::bind(&State_CharacterSelect::_##state##Render, this, std::placeholders::_1); \
                            _updateFunction = std::bind(&State_CharacterSelect::_##state##Update, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)

State_CharacterSelect::State_CharacterSelect(){
	_state = SelectClass;
	STATE_CHANGE(SelectClass);
} 

void State_CharacterSelect::Render(World *w, Renderer *r){
	_renderFunction(r);
}

void State_CharacterSelect::Update(Stack<iGameState*> *s, World *w, char c){
	_updateFunction(s, w, c);
}

void State_CharacterSelect::_SelectClassRender(Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(0, CLASS_GRAPHIC(Class::NOCLASS, _isMale));
	r->prints(0, 14, "+-----------------------------------------------------------------------------+");
	r->printlns(2, "Select Character:");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(1, "[1] New Barbarian");
	r->printlns(1, "[2] New Paladin");
	r->printlns(1, "[3] New Assassin");
	r->printlns(1, "[4] New Wizard");
	r->printlns(1, "[5] New Druid");
	r->printlns(1, "[6] New Ranger");
	r->printlns(0, "+-----------------------------------------------------------------------------+"); 
}

void State_CharacterSelect::_SelectGenderRender(Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(0, CLASS_GRAPHIC(Class::NOCLASS, _isMale));
	r->prints(0, 14, "+-----------------------------------------------------------------------------+");
	r->printlns(2, "Choose Gender:");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(1, "[1] Male");
	r->printlns(1, "[2] Female");
	r->printlns(1, "");
	r->printlns(1, "");
	r->printlns(1, "");
	r->printlns(1, "[A] Back");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
}

void State_CharacterSelect::_ClassInfoRender(Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(0, "");
	r->printlns(0, CLASS_GRAPHIC(_selectedClass, _isMale));
	r->prints(0, 15, "+-----------------------------------------------------------------------------+");
	r->printlns(1, CLASS_INFO(_selectedClass));
	r->prints(0, 23, "+-----------------------------------------------------------------------------+");
	r->prints(27,24, "Press any key to continue");
}

void State_CharacterSelect::_SelectPersonalityRender(Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(0, "");
	r->printlns(0, CLASS_GRAPHIC(_selectedClass, _isMale));
	r->prints(0, 15, "+-----------------------------------------------------------------------------+");
	r->printlns(2, "Choose Personality:");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(1, CLASS_PERSONALITY(_selectedClass));
	r->prints(1, 21, "");
	r->printlns(1, "[A] Back");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
}

void State_CharacterSelect::_SelectGameModeRender(Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(0, "");
	r->printlns(0, CLASS_GRAPHIC(_selectedClass, _isMale));
	r->prints(0, 15, "+-----------------------------------------------------------------------------+");
	r->printlns(2, "Choose Game Mode:");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(1, "[1] Casual  = [Death is just a minor setback...] [-10%%%% Item Drop Rate]");
	r->printlns(1, "[2] Classic = [No respawns. Death is permanent.]");
	r->printlns(1, "");
	r->printlns(1, "");
	r->printlns(1, "[A] Back");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
}

void State_CharacterSelect::_SelectRaceCatagoryRender(Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(0, "");
	r->printlns(0, CLASS_GRAPHIC(_selectedClass, _isMale));
	r->prints(0, 15, "+-----------------------------------------------------------------------------+");
	r->printlns(2, "Choose Race Catagory:");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(1, "[1] Mystical  = [The ability to bend the elements to your will]");
	r->printlns(1, "[2] Powerful  = [The strength to take down enemies with brute force]");
	r->printlns(1, "[3] Steadfast = [The endurance to stop the most devastating of foes]");
	r->printlns(1, "");
	r->printlns(1, "[A] Back");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
}

void State_CharacterSelect::_SelectRaceRender(Renderer *r){
	std::string raceCategoryName;
	std::string race1[2];
	std::string race2[2];
	std::string race3[2];
	switch(_raceCategory){
		case Mystical:
			raceCategoryName = "Mystical";
			race1[0] = "[1] Human";
			race1[1] = "As typical as they come, in all shapes and sizes.\nUPPER-CLASS: Starts wih an additional 5 EXTRA MP\nHOMEOSTASIS: Generates +2 to ABILITY meter per turn\nBOOTSTRAPS:  Heals self upon enemy MISS/STUNNED (INT)";
			race2[0] = "[2] Silian";
			race2[1] = "Machine, robot, and biological; one of these they are not.\nDICE ROLL:   When using HEAL, grants 3%%%% chance to fully heal\nOVERFLOW:    HP regenerates when ULT meter is charged (VIT)\nAEGIS CHIP:  Heals self upon REPOSITIONING (INT)";
			race3[0] = "[3] Kraste";
			race3[1] = "A nomadic race of ice people, they love to procreate often.\nICE COMPLEX: Grants 10%%%% chance to freeze enemies\nNIGHTSHADE:  Deals bonus damage per turn to enemy (INT)\nSENESCENCE:  Enemy takes damage equal to your MP per turn";
			break;
		case Powerful:
			raceCategoryName = "Powerful";
			race1[0] = "[1] Flammkin";
			race1[1] = "Charred with hellfire, these firebreathers relish in blood.\nDRY HEAT:    When using HEAL, 5%%%% chance to BLEED enemies\nBRICK OVEN:  Grants immunity to MOLTEN and VAMPIRIC\nDEADLY VIEW: Using your ULTIMATE will BLEED enemies";
			race2[0] = "[2] Jotunnar";
			race2[1] = "Dwarven inhabitants of Jotun, these men truly enjoy pain.\nIRON MAIDEN: Enemies take damage when player is BLEEDING\nFURY WHIP:   ULTIMATE deals bonus damage to weakened enemies\nPAINBRINGER: When HP is low, 10%%%% chance to +10%%%% MAX HP";
			race3[0] = "[3] Wyspera";
			race3[1] = "These dark shadow creatures are truly one with nature.\nSHADOW RUN:  Dodge chance is passively increased by 5%%%%\nDARKLING:    ULTIMATE damage increases with level (DEX)\nWALLFLOWER:  Grants +5 bonus MP during REPOSITION";
			break;
		case Steadfast:
			raceCategoryName = "Steadfast";
			race1[0] = "[1] Goern";
			race1[1] = "These tough amphibians reside on land, but love the water.\nIRON SCALES: Grants 50%%%% resistance against BLEEDING\nHARD SELL:   Using HEAL will heal a bonus amount (DEX)\nEVASIVE TOE: Dodge chance increases when player HP is lowered";
			race2[0] = "[2] Sonite";
			race2[1] = "At a glance, their skin could be mistaken for soft stone.\nTENACITY:    HEAL is more effective in prolonged battles\nABSORBANT:   Using HEAL temporarily increases MAX HP (VIT)\nCRUMPLE:     Reduce enemy CHARGE damage by 40%%%%";
			race3[0] = "[3] Huskian";
			race3[1] = "Standing at over eight feet tall, these giants are unshakable.\nLIFELINK:    Grants 5%%%% chance per turn to heal 25%%%% of MAX HP\nBLOODSCENT:  ABILITY meter +10 if you or enemy is bleeding\nGUARD CRUSH: Has 33%%%% chance to break GUARDING enemy per turn";
			break;
	}
	r->printlns(0,  "+-----------------------------------------------------------------------------+");
	r->printlns(36,  raceCategoryName);
	r->printlns(0,  "+-----------------------------------------------------------------------------+");
	r->prints(3,5,  race1[0]);
	r->prints(17,5, race1[1].c_str());
	r->prints(3,10, race2[0]);
	r->prints(17,10,race2[1].c_str());
	r->prints(3,15, race3[0]);
	r->prints(17,15,race3[1].c_str());
	r->prints(3,21, "[A] Back");
	r->printlns(0,  "");
	r->printlns(0,  "+-----------------------------------------------------------------------------+");
}

void State_CharacterSelect::_EnterNameRender(Renderer *r){
	r->prints(2, 2, "Enter name: %s", _name.c_str());
}

void State_CharacterSelect::_BackStoryRender(Renderer *r){
	r->prints(2, 2, "Your name is %s. You are a %s, of %s descent.", _name.c_str(), CLASS_NAME(_selectedClass).c_str(), RACE_NAME(_selectedRace).c_str());
	r->prints(2, 4, BIRTH().c_str());
	r->prints(2, 6, UPBRINGING().c_str());
	r->prints(2, 8, REGRET().c_str());
	r->prints(2, 10, ENJOY().c_str());
	r->prints(2, 12, TODAY().c_str());
	r->prints(2, 14, MISC().c_str());
	r->prints(2, 16, SUDDENLY().c_str());
	r->prints(2, 18, UNSURE().c_str());
	r->prints(2, 20, "This is your story.");
}

void State_CharacterSelect::_SelectClassUpdate(Stack<iGameState*> *s, World *w, char c){
	switch(c){
		case '1':
			_selectedClass = Class::BARBARIAN;
			STATE_CHANGE(SelectGender);
			break;
		case '2':
			_selectedClass = Class::PALADIN;
			STATE_CHANGE(SelectGender);
			break;
		case '3':
			_selectedClass = Class::ASSASSIN;
			STATE_CHANGE(SelectGender);
			break;
		case '4':
			_selectedClass = Class::WIZARD;
			STATE_CHANGE(SelectGender);
			break;
		case '5':
			_selectedClass = Class::DRUID;
			STATE_CHANGE(SelectGender);
			break;
		case '6':
			_selectedClass = Class::RANGER;
			STATE_CHANGE(SelectGender);
			break;
		case 'a':
			s->Pop();
			break;
	}
}

void State_CharacterSelect::_SelectGenderUpdate(Stack<iGameState*> *s, World *w, char c){
	switch(c){
		case '1':
			_isMale = true;
			STATE_CHANGE(ClassInfo);
			break;
		case '2':
			_isMale = false;
			STATE_CHANGE(ClassInfo);
			break;
		case 'a':
			STATE_CHANGE(SelectClass);
			break;
	}
}

void State_CharacterSelect::_ClassInfoUpdate(Stack<iGameState*> *s, World *w, char c){
	STATE_CHANGE(SelectPersonality);
}

void State_CharacterSelect::_SelectPersonalityUpdate(Stack<iGameState*> *s, World *w, char c){
	if( c == 'a' ){
		STATE_CHANGE(SelectGender);
	}
	if( c >= 49 && c <= 51 ){
		_selectedPersonality = c - 49;
		STATE_CHANGE(SelectGameMode);
	}
}

void State_CharacterSelect::_SelectGameModeUpdate(Stack<iGameState*> *s, World *w, char c){
	switch(c){
		case '1':
			STATE_CHANGE(SelectRaceCatagory);
			break;
		case '2':
			STATE_CHANGE(SelectRaceCatagory);
			break;
		case 'a':
			STATE_CHANGE(SelectPersonality);
			break;
	}
}

void State_CharacterSelect::_SelectRaceCatagoryUpdate(Stack<iGameState*> *s, World *w, char c){
	switch(c){
		case '1':
			STATE_CHANGE(SelectRace);
			_raceCategory = Mystical;
			break;
		case '2':
			STATE_CHANGE(SelectRace);
			_raceCategory = Powerful;
			break;
		case '3':
			STATE_CHANGE(SelectRace);
			_raceCategory = Steadfast;
			break;
		case 'a':
			STATE_CHANGE(SelectGameMode);
			break;
	}
}

void State_CharacterSelect::_SelectRaceUpdate(Stack<iGameState*> *s, World *w, char c){
	Race races[3][3] = {{Race::HUMAN, Race::SILIAN, Race::KRASTE},
	                  {Race::FLAMMKIN, Race::JOTUNNAR, Race:: WYSPERA},
	                  {Race::GOERN, Race::SONITE, Race::HUSKIAN}};
	if( c == 'a' ){
		STATE_CHANGE(SelectRaceCatagory);
	}
	if( c >= 49 && c <= 51){
		_selectedRace = races[_raceCategory][c-49];
		STATE_CHANGE(EnterName);
	}
}

void State_CharacterSelect::_EnterNameUpdate(Stack<iGameState*> *s, World *w, char c){
	if( c == 8 ){ //Backspace
		if( _name.size() > 0 )
			_name.pop_back();
	}
	if( c == 13 ){ //Return
		STATE_CHANGE(BackStory);
	}
	if( c < 65 ) return;
	if( _name.size() < 20 )
		_name+= c;
}

void State_CharacterSelect::_BackStoryUpdate(Stack<iGameState*> *s, World *w, char c){
	w->SetPlayer(new Character(_selectedClass, _selectedRace, _name, _selectedPersonality));
	s->Replace(new State_GameMode());
}
