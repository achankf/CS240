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
	int prev = output_array[0];
	if (k == 0) return 0;
	for (int i = 0;;){
		cout << output_array[i] << ' ';
		i++;
		if (i >= k || i >= num_input_values) break;
		if (output_array[i] < prev){
			cout << "ERROR"<<endl;
			return 0;
		}
	}
	cout << endl;
}
