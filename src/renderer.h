#ifndef _RENDERER_H
#define _RENDERER_H

#include <string>
#include <memory>

class TCODConsole;

class Renderer{
public:
	Renderer();
	~Renderer();
	void            prints( int x, int y, std::string s, ... );
	void            printlns( int x, std::string s, ... );
	void            print( std::string s, ... );
	void            printc( int x, int y, char c );
	void            Flush( );
	void            Debug( std::string s, ... );
	bool            isClosed( );
private:
	int             _line;
	int             _debug_line;
	std::unique_ptr<TCODConsole> _console;
};

#endif
