DEBUG = -DDEBUG -ggdb # -DALFRED_DEBUG
CXXFLAGS = $(DEBUG) -pedantic-errors -Werror -march=native $(INCLUDE_DIR) -Wall $(OLEVEL) -pipe

all: normal.exe seq.exe exp.exe

seq.exe : isearch.cpp isearch_seq.cpp
	g++ $(CXXFLAGS) -DSEQ isearch.cpp -o $@

exp.exe : isearch.cpp isearch_exp.cpp
	g++ $(CXXFLAGS) -DEXP isearch.cpp -o $@

normal.exe : isearch.cpp isearch_normal.cpp
	g++ $(CXXFLAGS) -DNORMAL isearch.cpp -o $@

.phony: clean
clean:
	rm -f *.o *.exe
