#include "util.h"
#include <stdarg.h>

namespace moon{

std::string BuildString(std::string s, ...){
	char *text = new char[512];
	va_list ap;
	va_start(ap, s);
	vsprintf(text, s.c_str(), ap);
	va_end(ap);
	std::string result(text);
	delete text;
	return result;
}

}