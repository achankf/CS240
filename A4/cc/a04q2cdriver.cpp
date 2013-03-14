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
	MAX = 1000000,
	NUM_WANTED = 100000
};

list<int> inserted;

// -t specified
void numFromStdIn(BinarySearchTree &bst){
	int num;
	cin >> num;
	for (int i = 0, temp; i < num; i++){
		cin >> temp;
		bst.Insert(temp);
		inserted.push_back(temp);
		//bst.print();
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
		if (bst.Insert(temp)){
			inserted.push_back(temp);
			i++;
		}
	}
	if (!bst.integ()) throw 1;
}

int main(int argc, char **argv){
	BinarySearchTree bst;

	try{
		if (argc == 2 && strcmp(argv[1], "-t") == 0){
			numFromStdIn(bst);
		} else {
			numFromRand(bst);
		}
		cout << set_color(GREEN) << "Execution Successful"<<endl;
	} catch (int a){
		cerr << inserted.size() << endl;
		for (std::list<int>::iterator it = inserted.begin(); it != inserted.end(); it++){
			cerr << *it << ' ';
		} cerr << endl;
		cout << set_color(RED)<< "Exception catched at " << inserted.size() <<"th item"<< endl;
		cout << set_color();
		return 1;
	}
	cout << set_color();

	return 0;
}
