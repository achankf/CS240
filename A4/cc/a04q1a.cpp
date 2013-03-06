#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <sys/time.h>
using namespace std;

enum {
	MAX = 10000,
	NUM_WANTED = 40,
	MODULO = 40
};

int h(int EID){
	int ret = 0;
	for (int i = 0; i < 4; i++){
		ret += EID % 10;
		EID /= 10;
	}
	return ret;
}

void printRet(int *ret){
	for (int i = 0; i < MODULO; i++){
		cout << i << " " << ret[i] << endl;
	}
}

void numFromStdIn(){
	int ret[MODULO] = {0};
	for (int i = 0, temp; i < NUM_WANTED; i++){
		cin >> temp;
		ret[h(temp)]++;
	}

	printRet(ret);
}

void numFromRand(){
	bool countArray[MAX] = {false};
	int ret[MODULO] = {0};

	struct timeval tv;
	gettimeofday(&tv, NULL);
	// set seed
	srand(tv.tv_sec * 1000000 + tv.tv_usec);

	// generate 40 unique random numbers
	for (int count = 0; count < 40;){
		int temp = rand() % MAX;
		if (countArray[temp]) continue;
		countArray[temp] = true;
		ret[h(temp)]++;
		count++;
	}

	printRet(ret);
}

int main(int argc, char **argv){
	if (argc == 2 && strcmp(argv[1], "-t") == 0){
		numFromStdIn();
	} else {
		numFromRand();
	}

	return 0;
}
