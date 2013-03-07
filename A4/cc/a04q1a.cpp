#include <iostream>
#include <cstdlib>
#include <ctime> // for setting seed
#include <cstring>
#include <sys/time.h> // for setting seed
#include <list>
#include <vector>
using namespace std;

// vector is a bit overkill
typedef vector<list<int> > hashtable;

enum {
	MAX = 10000,
	NUM_WANTED = 40,
	MODULUS = 40
};

int h(int EID){
	int ret = 0;
	for (int i = 0; i < 4; i++){
		ret += EID % 10;
		EID /= 10;
	}
	return ret;
}

void printCollision(hashtable &table){
	for (int i = 0; i < MODULUS; i++){
		cout << i << " " << table[i].size() << endl;
	}
}

// -t specified
void numFromStdIn(hashtable &table){
	for (int i = 0, temp; i < NUM_WANTED; i++){
		cin >> temp;
		table[h(temp)].push_front(temp);
	}
}

// -t is not specified
void numFromRand(hashtable &table){
	// countArray makes sure all numbers are unique
	bool countArray[MAX] = {false};

	// get time
	struct timeval tv; gettimeofday(&tv, NULL);
	// set seed
	srand(tv.tv_sec * 1000000 + tv.tv_usec);

	// generate 40 unique random numbers
	for (int count = 0; count < NUM_WANTED;){
		int temp = rand() % MAX;
		if (countArray[temp]) continue;
		countArray[temp] = true;
		table[h(temp)].push_front(temp);
		count++;
	}
}

int main(int argc, char **argv){
	hashtable table(MODULUS);

	if (argc == 2 && strcmp(argv[1], "-t") == 0){
		numFromStdIn(table);
	} else {
		numFromRand(table);
	}

	printCollision(table);
	return 0;
}
