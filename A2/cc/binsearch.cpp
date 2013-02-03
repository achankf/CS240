#include <iostream>
using namespace std;

int bs(int *a, int s, int t){
	int low, high;
	low = 0;
	high = s;
	int pivot = 0;
	int islow = 0;
	while(true){
		if (high < low) break;
		pivot = (high+low)/2;
		if (t > a[pivot]){
			low = pivot + 1;
			islow = 1;
		} else if (t < a[pivot]){
			high = pivot -1;
			islow = 0;
		} else {
			return pivot;
		}
	}
	return pivot + islow;
}

int main(){
	const int size = 8;
	int a[size] = {-10, 1 ,2,3,4,5,6,9};
#if 1
	for (int k  = 0 ; k < 7;k++){
		int i = bs(a,7, k+1);
		cout << "i:"<< i << " a[i]"<< a[i]<<endl;
	}
#endif
{
	int i = bs(a,size,0);
	cout << "i:"<< i << " a[i]"<< a[i]<<endl;
}

{
	int i = bs(a,size,8);
	cout << "i:"<< i << " a[i]"<< a[i]<<endl;
}

{
	int i = bs(a,size,10);
	cout << "i:"<< i << " a[i]"<< a[i]<<endl;
}

}
