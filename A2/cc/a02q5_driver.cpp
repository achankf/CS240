#include <iostream>
using namespace std;

void k_smallest( int* input_array, int num_input_values, int* output_array, int k );

int main(){
	int num_input_values, k;
	cin >> num_input_values;
	cin >> k;
	int input_array[num_input_values];
	int output_array[num_input_values];
	for (int i = 0; i < num_input_values; i++){
		cin >> input_array[i];
	}
	k_smallest( input_array, num_input_values, output_array, k);
	for (int i = 0; i < k; i++){
		cout << output_array[i] << ' ';
	}
	cout << endl;
}
