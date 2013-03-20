#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <sys/time.h> // for setting seed
#define SIZE 10000
using namespace std;

int interpolate(int *A, int l, int r, int k){
	return l + ((float)(k-A[l]) / (A[r]-A[l]) * (r-l));
}

int i_search(int *A, int l, int r, int k){
	int i = interpolate(A, l, r, k);
//cout << "i:" << i << " A[i]:" << A[i] << " l:" << l << " r:" << r << " k:" << k<< endl;
	if (l >= r) return l;

	if (A[i] > k){
		if (i == r) i--;
		return i_search(A, l, i, k);
	} else if (A[i] < k){
		if (i == l) i++;
		return i_search(A, i, r, k);
	}
	return i;
}

int nextRand(){
	return rand() % 10 + 1;
}

void numFromStdIn(int *A, int *k){
	cin >> *k;
	for (int i = 0; i < SIZE; i++){
		cin >> A[i];
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
	srand(tv.tv_sec * 1000000 + tv.tv_usec);

	int A[SIZE];
	int k;

	if (argc == 2 && strcmp(argv[1], "-t") == 0){
		numFromStdIn(A, &k);
	} else {
		numFromRand(A);
		k = A[rand() % SIZE];
	}

	cerr << k << endl;
	for (int i = 0; i < SIZE; i++){
		cerr << A[i] << ' ';
	} cerr << endl;
	cout << "require:" << k << endl;
	int temp = i_search(A, 0, SIZE-1, k);
	cout << "search ret:" << temp << ' ' << A[temp] << endl;
}
