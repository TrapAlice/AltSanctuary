#include "renderer.h"
#include "libtcod.hpp"
#include <stdarg.h>
#include <cstdio>

Renderer::Renderer()
	: _line(0)
	, _debug_line(0)
{
	_console = std::unique_ptr<TCODConsole>(new TCODConsole(80,25));
	TCODConsole::setCustomFont("terminal.png", TCOD_FONT_LAYOUT_ASCII_INROW, 0, 0);
	TCODConsole::initRoot(80,25,"AltSanctuary");
}

Renderer::~Renderer()
{
}

void Renderer::prints(const int& x, const int& y, const std::string& s, ...){
	char text[2000];
	va_list ap;
	va_start(ap, s);
	vsprintf(text, s.c_str(), ap);
	va_end(ap);

	_line=y+1;

	_console->print(x, y, text);
}

void Renderer::printlns(const int& x, const std::string& s, ...){
	char text[2000];
	va_list ap;
	va_start(ap, s);
	vsprintf(text, s.c_str(), ap);
	va_end(ap);
	
	_console->print(x, _line, text);
	++_line;
}

void Renderer::print(const std::string& s, ...) const{
	char text[2000];
	va_list ap;
	va_start(ap, s);
	vsprintf(text, s.c_str(), ap);
	va_end(ap);

	_console->print(_x, _line, text);
}

void Renderer::printc(const int& x, const int& y, const char& c) const{
	_console->print( x, y, &c);
}

void Renderer::Debug(const std::string& s, ...){
	char text[2000];
	va_list ap;
	va_start(ap, s);
	vsprintf(text, s.c_str(), ap);
	va_end(ap);

	_console->print( 82, 5+_debug_line, text);
	++_debug_line;
}

void Renderer::Flush(){
	TCODConsole::root->clear();
	TCODConsole::blit(_console.get(),0,0,80,25,TCODConsole::root,0,0);
	TCODConsole::flush();
	_console->clear();
	_line=0;
	_debug_line=0;
}

bool Renderer::isClosed() const{
	return TCODConsole::isWindowClosed();
}