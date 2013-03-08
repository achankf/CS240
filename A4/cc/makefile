CXX = g++
OLEVEL = -ggdb -O2
DEBUG = -DNDEBUG -pedantic-errors -Werror -march=native -Wall
CXXFLAGS = -march=native $(DEBUG) $(INCLUDE_DIR) $(OLEVEL) -pipe
EXE = a04q1a.exe a04q1c.exe a04q2cdriver.exe

all: $(EXE)

a04q1a.exe: a04q1a.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

a04q1c.exe: a04q1c.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

a04q2c.o : a04q2c.cpp a04q2c.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

a04q2cdriver.exe: a04q2cdriver.cpp a04q2c.o
	$(CXX) $(CXXFLAGS) $< -o $@

.phony: clean

clean:
	rm -rf *.o depend.temp $(EXE)
