#include "a04q2c.h"

#include <iostream>
#include <cstdlib>
#include <ctime> // for setting seed
#include <cstring>
#include <sys/time.h> // for setting seed
#include <list>
#include <vector>
using namespace std;

enum {
	MAX = 10000,
	NUM_WANTED = 1000
};

// -t specified
void numFromStdIn(BinarySearchTree &bst){
	int num;
	cin >> num;
	for (int i = 0, temp; i < num; i++){
		cin >> temp;
		bst.Insert(temp);
bst.print();
			if (!bst.integ()) throw 1;
	}
}

// -t is not specified
void numFromRand(BinarySearchTree &bst){
	// countArray makes sure all numbers are unique
	bool countArray[MAX] = {false};

	// get time
	struct timeval tv; gettimeofday(&tv, NULL);
	// set seed
	srand(tv.tv_sec * 1000000 + tv.tv_usec);

	// generate 40 unique random numbers
	for (int i = 0; i < NUM_WANTED;){
		int temp = rand() % MAX;
		if (countArray[temp]) continue;
		countArray[temp] = true;
cout << "Inserting:"<<temp<<endl;
		if (bst.Insert(temp)){
bst.print();
			if (!bst.integ()) throw 1;
			i++;
		}
	}
}

int main(int argc, char **argv){
	BinarySearchTree bst;

	if (argc == 2 && strcmp(argv[1], "-t") == 0){
		numFromStdIn(bst);
	} else {
		numFromRand(bst);
	}

	return 0;
}
