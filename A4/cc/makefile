DEBUG = -DDEBUG -DALFRED_DEBUG -ggdb
CXXFLAGS = $(DEBUG) -pedantic-errors -Werror -march=native $(INCLUDE_DIR) -Wall $(OLEVEL) -pipe

all: a04q2cdriver.exe a04q1a.exe a04q1c.exe

a04q1a.exe : a04q1a.cpp
	g++ $(CXXFLAGS) $< -o $@

a04q1c.exe : a04q1c.cpp
	g++ $(CXXFLAGS) $< -o $@

a04q2c.o: a04q2c.cpp a04q2c.h
	g++ $(CXXFLAGS) -c $< -o $@

a04q2cdriver.exe : a04q2cdriver.cpp a04q2c.o
	g++ $(CXXFLAGS) a04q2cdriver.cpp a04q2c.o -o $@

.phony: clean
clean:
	rm -f *.o *.exe
