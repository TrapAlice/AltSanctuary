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
			break;
		case Powerful:
			raceCategoryName = "Powerful";
			break;
		case Steadfast:
			raceCategoryName = "Steadfast";
			break;
	}
	r->printlns(0,  "+-----------------------------------------------------------------------------+");
	r->printlns(36,  raceCategoryName);
	r->printlns(0,  "+-----------------------------------------------------------------------------+");
	r->prints(3,5,  race1[0]);
	r->prints(17,5, race1[1].c_str());
	r->prints(3,10, "");
	r->prints(17,10,"");
	r->prints(3,15, "");
	r->prints(17,15,"");
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
