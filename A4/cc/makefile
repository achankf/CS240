CXX = g++
OLEVEL = -ggdb -O2
DEBUG = -DNDEBUG -pedantic-errors -Werror -march=native -Wall
CXXFLAGS = -march=native $(DEBUG) $(INCLUDE_DIR) $(OLEVEL) -pipe
EXE = a04q1a.exe

all: $(EXE)

a04q1a.exe: a04q1a.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.phony: clean

clean:
	rm -rf *.o depend.temp $(EXE)
