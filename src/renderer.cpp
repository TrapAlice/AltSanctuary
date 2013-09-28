#include "renderer.h"

#include <stdarg.h>
#include <cstdio>
#include "libtcod.hpp"

Renderer::Renderer(){
	console_ = new TCODConsole(80,25);
	TCODConsole::setCustomFont("terminal.png", TCOD_FONT_LAYOUT_ASCII_INROW, 0, 0);
	TCODConsole::initRoot(80,25,"Sanctuary");
	line_ = 0;
	debug_line_ = 0;
}

Renderer::~Renderer(){
	delete console_;
}

void Renderer::prints(int x, int y, std::string s, ...){
	char *text;
	va_list ap;
	text = new char[2000];
	va_start(ap, s);
	vsprintf(text, s.c_str(), ap);
	va_end(ap);

	line_=y+1;

	console_->print(x, y, text);
	delete(text);
}

void Renderer::printlns(int x, std::string s, ...){
	char *text;
	va_list ap;
	text = new char[2000];
	va_start(ap, s);
	vsprintf(text, s.c_str(), ap);
	va_end(ap);
	
	console_->print(x, line_, text);
	line_++;
}

void Renderer::print(std::string s, ...){
	char *text;
	va_list ap;
	text = new char[2000];
	va_start(ap, s);
	vsprintf(text, s.c_str(), ap);
	va_end(ap);

	//console_->print( text);
	delete(text);
}

void Renderer::printc(int x, int y, char c){
	console_->print( x, y, &c);
}

void Renderer::Debug(std::string s, ...){
	char *text;
	va_list ap;
	text = new char[2000];
	va_start(ap, s);
	vsprintf(text, s.c_str(), ap);
	va_end(ap);

	console_->print( 82, 5+debug_line_, text);
	debug_line_++;
	delete(text);
}

void Renderer::Flush(){
	TCODConsole::root->clear();
	TCODConsole::blit(console_,0,0,80,25,TCODConsole::root,0,0);
	TCODConsole::flush();
	console_->clear();
	line_=0;
	debug_line_=0;
}

bool Renderer::isClosed(){
	return TCODConsole::isWindowClosed();
}