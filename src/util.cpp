#include "util.h"
#include <iterator>
#include <stdarg.h>
#include <sstream>

namespace moon{

std::string BuildString(const std::string& s, ...){
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