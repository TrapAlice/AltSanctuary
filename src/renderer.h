#ifndef _RENDERER_H
#define _RENDERER_H

#include <memory>
#include <string>

class TCODConsole;

class Renderer{
public:
	Renderer();
	~Renderer();
	void            prints(const int& x, const int& y, const std::string& s, ...);
	void            printlns(const int& x, const std::string& s, ...);
	void            print(const std::string& s, ...) const;
	void            printc(const int& x, const int& y, const char& c) const;
	void            Flush();
	void            Debug(const std::string& s, ...);
	bool            isClosed() const;
private:
	int             _line;
	int             _debug_line;
	std::unique_ptr<TCODConsole> _console;
};

#endif
