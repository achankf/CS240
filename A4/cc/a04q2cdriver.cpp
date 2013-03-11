#include "a04q2c.h"

#include <cstdlib>
#include <ctime> // for setting seed
#include <sys/time.h> // for setting seed
using namespace std;

int main(){
	BinarySearchTree bst;
	struct timeval tv; gettimeofday(&tv, NULL);
	srand(tv.tv_sec * 1000000 + tv.tv_usec);
	int num = 10;
	int range = 10000;
	bool *count = new bool [range];
	for (int i = 0; i < range; i++){
		count[i] = false;
	}
	for (int i = 0; i< num;){
		int temp = rand() %range;
		if (count[temp]) continue;
		count[temp] = true;
		if (bst.Insert(temp)) i++;
		else throw 3;
	}
	cout << " END OF INSERT"<< endl;
	delete [] count;
}
