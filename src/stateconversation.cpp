#include "stateconversation.h"
#include "graphic.h"
#include "renderer.h"

State_Conversation::State_Conversation(Conversation c){
	_position = 0;
	_speaker_name = "Unknown Stranger";
	_speaker_graphic = Graphic::DIANE;
	_text.push_back("> Brave adventurer! You may be experiencing some discomfort.");
	_text.push_back("> I thought you\'d want to survive out here, so I brought you a few things");
	_text.push_back("> It's just some silver, gold, and a weapon, but it\'ll have to do for now.");
	_text.push_back("> Go to Gate 16. Our world is in dire need of your help...");
	_text.push_back("> Go to Gate 16. Our world is in dire need of your help... I must go now.");
}

void State_Conversation::Render( World *w, Renderer *r){
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->prints(40-_speaker_name.length()/2, 1, _speaker_name.c_str());
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(0, GRAPHIC(_speaker_graphic));
	r->prints(0, 16, "+-----------------------------------------------------------------------------+");
	r->printlns(0, _text[_position]);
	r->printlns(0, "+-----------------------------------------------------------------------------+");
	r->printlns(0, "");
	r->printlns(0, "");
	r->printlns(0, "");
	r->printlns(0, "");
	r->printlns(0, "+-----------------------------------------------------------------------------+");
}

void State_Conversation::Update( Stack<iGameState*> *s, World *w, char c){
	++_position;
	if(_position == _text.size()){
		s->Pop();
	}
}