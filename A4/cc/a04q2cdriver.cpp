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
	MAX = 100000,
	NUM_WANTED = 5000
};

list<int> inserted;

// -t specified
void numFromStdIn(BinarySearchTree &bst){
	int num;
	cin >> num;
	for (int i = 0, temp; i < num; i++){
		cin >> temp;
		bst.Insert(temp);
		//inserted.push_back(temp);
		cout << i << endl;
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
		if (bst.Insert(temp)){
			//inserted.push_back(temp);
			i++;
		}
	}
	//if (!bst.integ()) throw 1;
}

int main(int argc, char **argv){
	BinarySearchTree bst;

	try{
		if (argc == 2 && strcmp(argv[1], "-t") == 0){
			numFromStdIn(bst);
		} else {
			numFromRand(bst);
		}
		cout << "Execution Successful"<<endl;
	} catch (int a){
#if 0
		cerr << inserted.size() << endl;
		for (std::list<int>::iterator it = inserted.begin(); it != inserted.end(); it++){
			cerr << *it << ' ';
		} cerr << endl;
#endif
		cout << "Exception catched at " << inserted.size() <<"th item"<< endl;
		return 1;
	}
	return 0;
}
