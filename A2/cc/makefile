CXX = g++
OLEVEL = -O2
OLEVEL = -ggdb
DEBUG = -DNDEBUG
CXXFLAGS = -march=native $(DEBUG) $(INCLUDE_DIR) -Wall $(OLEVEL) -pipe

all: a02q4b a02q5b

a02q4b.o: a02q4b.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $<

a02q4_driver.cpp:

a02q4_driver.o: a02q4_driver.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $<

a02q4b: a02q4b.o a02q4_driver.o
	$(CXX) $(CXXFLAGS) $^ -o $@

a02q5b.o: a02q5b.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $<

a02q5b: a02q5b.o
	$(CXX) $(CXXFLAGS) a02q5_driver.cpp $^ -o $@

.phony: clean

clean:
	rm -rf *.o depend.temp $(EXE)
