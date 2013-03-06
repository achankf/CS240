#include <iostream>
#include <cstdlib>
#include <ctime> // for setting seed
#include <cstring>
#include <sys/time.h> // for setting seed
#include <list>
using namespace std;

typedef list<int> keylist;

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

void printRet(keylist *hashtable){
	for (int i = 0; i < MODULUS; i++){
		cout << i << " " << hashtable[i].size() << endl;
	}
}

void numFromStdIn(keylist *hashtable){
	for (int i = 0, temp; i < NUM_WANTED; i++){
		cin >> temp;
		hashtable[h(temp)].push_front(temp);
	}

	printRet(hashtable);
}

void numFromRand(keylist *hashtable){
	bool countArray[MAX] = {false};

	// get time
	struct timeval tv; gettimeofday(&tv, NULL);
	// set seed
	srand(tv.tv_sec * 1000000 + tv.tv_usec);

	// generate 40 unique random numbers
	for (int count = 0; count < 40;){
		int temp = rand() % MAX;
		if (countArray[temp]) continue;
		countArray[temp] = true;
		hashtable[h(temp)].push_front(temp);
		count++;
	}

	printRet(hashtable);
}

int main(int argc, char **argv){

	// could be vector if you want it to be more robust
	keylist hashtable[MODULUS];

	if (argc == 2 && strcmp(argv[1], "-t") == 0){
		numFromStdIn(hashtable);
	} else {
		numFromRand(hashtable);
	}

	// do things with the hashtable
	return 0;
}
