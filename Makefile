CC=g++
CFLAGS=-c -Wall -Iinclude -g
LDFLAGS= -Llib -ltcod -ltcodxx -Wl,-rpath=. 
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/altsanctuary

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean: clean-objects clean-executable

clean-objects:
	-rm src/*.o

clean-executable:
	-rm $(EXECUTABLE)

rebuild: clean all