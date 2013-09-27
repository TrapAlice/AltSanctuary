#include "statecharacterselect.h"
#include "stategamemode.h"
#include "renderer.h"
#include "character.h"
#include "world.h"
#include "dbg.h"

State_CharacterSelect::State_CharacterSelect(){
	_state = SelectClass;
}

State_CharacterSelect::~State_CharacterSelect(){}

void State_CharacterSelect::Render(World *w, Renderer *r){
	switch(_state){
		case SelectClass:
			_SelectClassRender(r);
			break;
		case SelectGender:
			_SelectGenderRender(r);
			break;
		case ClassInfo:
			_ClassInfoRender(r);
			break;
		case SelectPersonality:
			_SelectPersonalityRender(r);
			break;
		case SelectGameMode:
			_SelectGameModeRender(r);
			break;
		case SelectRaceCatagory:
			_SelectRaceCatagoryRender(r);
			break;
		case SelectRace:
			_SelectRaceRender(r);
			break;
		case EnterName:
			_EnterNameRender(r);
			break;
		case BackStory:
			_BackStoryRender(r);
			break;
	}
}

void State_CharacterSelect::Update(Stack<iGameState*> *s, World *w, char c){
	switch(_state){
		case SelectClass:
			switch(c){
				case '1':
					_selectedClass = Barbarian;
					_state = SelectGender;
					break;
				case '2':
					_selectedClass = Paladin;
					_state = SelectGender;
					break;
				case '3':
					_selectedClass = Assassin;
					_state = SelectGender;
					break;
				case '4':
					_selectedClass = Wizard;
					_state = SelectGender;
					break;
				case '5':
					_selectedClass = Druid;
					_state = SelectGender;
					break;
				case '6':
					_selectedClass = Ranger;
					_state = SelectGender;
					break;
				case 'a':
					s->Pop();
					break;
			}
			break;
		case SelectGender:
			switch(c){
				case '1':
					_isMale = true;
					_state = ClassInfo;
					break;
				case '2':
					_isMale = false;
					_state = ClassInfo;
					break;
				case 'a':
					_state = SelectClass;
					break;
			}
			break;
		case ClassInfo:
				_state = SelectPersonality;
			break;
		case SelectPersonality:
			switch(c){
				case '1':
					_state = SelectGameMode;
					break;
				case '2':
					_state = SelectGameMode;
					break;
				case '3':
					_state = SelectGameMode;
					break;
				case 'a':
					_state = SelectGender;
					break;
			}
			break;
		case SelectGameMode:
			switch(c){
				case '1':
					_state = SelectRaceCatagory;
					break;
				case '2':
					_state = SelectRaceCatagory;
					break;
				case 'a':
					_state = SelectPersonality;
					break;
			}
			break;
		case SelectRaceCatagory:
			switch(c){
				case '1':
					_state = SelectRace;
					_raceCategory = Mystical;
					break;
				case '2':
					_state = SelectRace;
					_raceCategory = Powerful;
					break;
				case '3':
					_state = SelectRace;
					_raceCategory = Steadfast;
					break;
				case 'a':
					_state = SelectGameMode;
					break;
			}
			break;
		case SelectRace:
			switch(c){
				case '1':
					_state = EnterName;
					break;
				case '2':
					_state = EnterName;
					break;
				case '3':
					_state = EnterName;
					break;
				case 'a':
					_state = SelectRaceCatagory;
					break;
			}
			break;
		case EnterName:
			if( c == 8 ){ //Backspace
				if( _name.size() > 0 )
					_name.pop_back();
			}
			if( c == 13 ){ //Return
				_state = BackStory;
			}
			if( c < 65 ) break;
			if( _name.size() < 20 )
				_name+= c;
			break;
		case BackStory:
			s->Replace(new State_GameMode());
			break;
	}
	
}


void State_CharacterSelect::_printBlankFace(Renderer* r){
	r->printlns(0, "");
	r->printlns(0, "                                   _.------._");
	r->printlns(0, "                                  :          :");
	r->printlns(0, "                                 :            :");
	r->printlns(0, "                                 :            :");
	r->printlns(0, "                                 :            :");
	r->printlns(0, "                                 :            :");
	r->printlns(0, "                                 :            :");
	r->printlns(0, "                                  :          :");
	r->printlns(0, "                                   :        :");
	r->printlns(0, "                                _.:::.____.:::._");
	r->printlns(0, "                            _.::::::::::::::::::::._");
	r->printlns(0, "                          .::::::::::::::::::::::::::.");
}

void State_CharacterSelect::_SelectClassRender(Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	_printBlankFace(r);
	r->printlns(0, "+-----------------------------------------------------------------------------+");
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
	_printBlankFace(r);
	r->printlns(0, "+-----------------------------------------------------------------------------+");
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
	//printClassGraphic(r);
	_printBlankFace(r);
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(1, "Regenerates 5%%%% of max HP each turn when health is below 50%%%%");
	r->printlns(1, "Increased healing ability based on RAGE meter.");
	r->printlns(1, "Gains 20 MP per Reposition.");
	r->printlns(1, "Increased lifesteal from lifesteal abilities.");
	r->printlns(1, "Gains additional attack power from points in VIT.");
	r->printlns(1, "Has chance for Whirlwind [2] to break GUARDING.");
	r->printlns(1, "Using Cleave [1] will remove ENSNARE effects.");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(27, "Press any key to continue");
}

void State_CharacterSelect::_SelectPersonalityRender(Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	_printBlankFace(r);
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(2, "Choose Personality:");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(1, "[1] Brave   = [+5 DEX, -3 STR] [First one in, last one out.]"); //Different per class
	r->printlns(1, "[2] Rash    = [+6 STR, -4 VIT] [In battle, there's no time for thinking.]");
	r->printlns(1, "[3] Adamant = [+3 VIT, -2 DEX] [You can't move a mountain with an ant.]");
	r->printlns(1, "");
	r->printlns(1, "");
	r->printlns(1, "[A] Back");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
}

void State_CharacterSelect::_SelectGameModeRender(Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	_printBlankFace(r);
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(2, "Choose Game Mode:");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(1, "[1] Casual  = [Death is just a minor setback...] [-10%%%% Item Drop Rate]");
	r->printlns(1, "[2] Classic = [No respawns. Death is permanent.]");
	r->printlns(1, "");
	r->printlns(1, "");
	r->printlns(1, "");
	r->printlns(1, "[A] Back");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
}

void State_CharacterSelect::_SelectRaceCatagoryRender(Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	_printBlankFace(r);
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(2, "Choose Race Catagory:");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(1, "[1] Mystical  = [The ability to bend the elements to your will]");
	r->printlns(1, "[2] Powerful  = [The strength to take down enemies with brute force]");
	r->printlns(1, "[3] Steadfast = [The endurance to stop the most devastating of foes]");
	r->printlns(1, "");
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
	r->printlns(0, "This is your story");
}
