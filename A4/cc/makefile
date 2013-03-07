CXX = g++
OLEVEL = -ggdb -O2
DEBUG = -DNDEBUG -pedantic-errors -Werror -march=native -Wall
CXXFLAGS = -march=native $(DEBUG) $(INCLUDE_DIR) $(OLEVEL) -pipe
EXE = a04q1a.exe a04q1c.exe a04q2adriver.exe

all: $(EXE)

a04q1a.exe: a04q1a.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

a04q1c.exe: a04q1c.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

a04q2a.o : a04q2a.cpp a04q2a.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

a04q2adriver.exe: a04q2adriver.cpp a04q2a.o
	$(CXX) $(CXXFLAGS) $< -o $@

.phony: clean

clean:
	rm -rf *.o depend.temp $(EXE)
