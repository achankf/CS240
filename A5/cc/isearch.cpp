#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <sys/time.h> // for setting seed
#define SIZE 1000
using namespace std;

int count = 0;

#ifdef BIN
#include "isearch_bin.cpp"
#endif
#ifdef NORMAL
#include "isearch_normal.cpp"
#endif
#ifdef SEQ
#include "isearch_seq.cpp"
#endif
#ifdef EXP
#include <cmath>
#include "isearch_exp.cpp"
#endif

int i_search(int *A, int l, int r, int k, int &numFailures){
	count++;
	int i = interpolate(A, l, r, k, numFailures);
	int num_left = i - l+1;
	int num_right = r - i;
	cout << i << " " << l << " " << r  << " " << numFailures<< endl;

	if (l == r){
		if (A[l] == k){
			return l; // handles case when A has one item
		} else {
			return -1;
		}
	}

	if (A[i] > k){
		//if (num_right > num_left) numFailures++;
		if (num_left > num_right) numFailures++;
		if (i == r) i--; // avoid recursing on the same "r"
		return i_search(A, l, i, k, numFailures);
	} else if (A[i] < k){
		//if (num_left > num_right) numFailures++;
		if (num_right > num_left) numFailures++;
		if (i == l) i++;
		return i_search(A, i, r, k, numFailures);
	}
	return i;
}

int nextRand(){
	return rand() % 10 + 1;
}

void numFromStdIn(int **A, int *size, int *k){
	cin >> *k;
	cin >> *size;
	*A = new int[*size];
	for (int i = 0; i < *size; i++){
		cin >> (*A)[i];
	}
}

void numFromRand(int *A){
	A[0] = nextRand();
	for (int i = 1; i < SIZE; i++){
		A[i] = A[i-1] + nextRand();
	}
}

int main(int argc, char **argv){
	struct timeval tv; gettimeofday(&tv, NULL);
	//srand(tv.tv_sec * 1000000 + tv.tv_usec);

	int *A, k, size;

	if (argc == 2 && strcmp(argv[1], "-t") == 0){
		numFromStdIn(&A, &size, &k);
	} else {
		A = new int [SIZE];
		srand(atoi(argv[1]));
		numFromRand(A);
		size = SIZE;
		k = A[rand() % SIZE];
	}

	cerr << k << endl;
	cerr << size << endl;
	for (int i = 0; i < size; i++){
		cerr << A[i] << ' ';
	} cerr << endl;
	cout << "require:" << k << endl;

	int numFailures = 0;
	int temp = i_search(A, 0, size-1, k, numFailures);
	if (temp != -1){
		cout << "search ret:" << temp << ' ' << A[temp] << " with " << count << " times interpolation" << endl;
	} else {
		cout << "NOT FOUND" << endl;
	}

	delete [] A;
}
