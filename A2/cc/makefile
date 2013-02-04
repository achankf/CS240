CXX = g++
OLEVEL = -ggdb -O2
DEBUG = -DNDEBUG
CXXFLAGS = -march=native $(DEBUG) $(INCLUDE_DIR) -Wall $(OLEVEL) -pipe
EXE = a02q4b.exe a02q5b.exe

all: $(EXE)

a02q4b.o: a02q4b.cpp
	$(CXX) $(CXXFLAGS) -c $<

a02q4_driver.cpp:

a02q4_driver.o: a02q4_driver.cpp
	$(CXX) $(CXXFLAGS) -c $<

a02q4_additional.o: a02q4_additional.cpp
	$(CXX) $(CXXFLAGS) -c $<

a02q4b.exe: a02q4b.o a02q4_driver.o a02q4_additional.o
	$(CXX) $(CXXFLAGS) $^ -o $@

a02q5b.o: a02q5b.cpp
	$(CXX) $(CXXFLAGS) -c $<

a02q5b.exe: a02q5b.o
	$(CXX) $(CXXFLAGS) a02q5_driver.cpp $^ -o $@

.phony: clean

clean:
	rm -rf *.o depend.temp $(EXE)
