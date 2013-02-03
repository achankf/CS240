class min_heap{
	int *array;
	int array_sz, num_values;

private:
	int left_child(int i);
	
public:
	min_heap(int *array, int size);
	int size();
	void heapify();
	int delete_min();
	void bubble_down(int start);
};

void swap(int *array, int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

min_heap::min_heap(int *array, int size) :
	array(array), array_sz(size), num_values(size)
{}

int min_heap::size(){
	return num_values;
}

int min_heap::left_child(int i){
	return 2*i + 1;
}

void min_heap::bubble_down(int start){
	int temp = array[start];
	int i = start, compare;
	while(true){
		compare = left_child(i);
		if (compare >= num_values) break;
		if (compare + 1 < num_values && array[compare] > array[compare+1]){
			compare++;
		}
		if (temp < array[compare]) break;
		swap(array, i, compare);
		i = compare;
	}
}

int min_heap::delete_min(){
	int ret = array[0];
	num_values--;
	array[0] = array[num_values];
	bubble_down(0);
	return ret;
}

void min_heap::heapify(){
	for(int i = (num_values-1)/2; i >= 0; i--){
		bubble_down(i);
	}
}

void k_smallest( int* input_array, int num_input_values, int* output_array, int k )
{
	int temp[num_input_values];

	for (int i = 0; i < num_input_values; i++){
		temp[i] = input_array[i];
	}

	min_heap heap(temp, num_input_values);
	heap.heapify();
	for (int i = 0; i < k; i++){
		output_array[i] = heap.delete_min();
	}
}
