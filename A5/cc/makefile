DEBUG = -DDEBUG -ggdb # -DALFRED_DEBUG
CXXFLAGS = $(DEBUG) -pedantic-errors -Werror -march=native $(INCLUDE_DIR) -Wall $(OLEVEL) -pipe

all: a5q1a.exe a5q1c.exe

a5q1a.exe : a5q1a.cpp
	g++ $(CXXFLAGS) $^ -o $@

a5q1c.exe : a5q1c.cpp
	g++ $(CXXFLAGS) $^ -o $@

.phony: clean
clean:
	rm -f *.o *.exe
