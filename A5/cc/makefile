DEBUG = -DDEBUG -ggdb -DALFRED_DEBUG
CXXFLAGS = $(DEBUG) -pedantic-errors -Werror -march=native $(INCLUDE_DIR) -Wall $(OLEVEL) -pipe

all: normal.exe seq.exe exp.exe bin.exe a05q3_main

seq.exe : isearch.cpp isearch_seq.cpp
	g++ $(CXXFLAGS) -DSEQ isearch.cpp -o $@

exp.exe : isearch.cpp isearch_exp.cpp
	g++ $(CXXFLAGS) -DEXP isearch.cpp -o $@

normal.exe : isearch.cpp isearch_normal.cpp
	g++ $(CXXFLAGS) -DNORMAL isearch.cpp -o $@

bin.exe : isearch.cpp isearch_bin.cpp
	g++ $(CXXFLAGS) -DBIN isearch.cpp -o $@

a05q3.o: a05q3.cpp
	g++ $(CXXFLAGS) $< -c

a05q3_main.o: a05q3_main.cpp
	g++ $(DEBUG) $< -c

sl_tester.o: sl_tester.cpp
	g++ $(DEBUG) $< -c

a05q3_main: a05q3_main.o a05q3.o sl_tester.o
	g++ $(DEBUG) $^ -o $@

.phony: clean
clean:
	rm -f *.o *.exe
