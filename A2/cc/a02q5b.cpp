void swap(int *array, int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int left_child(int i){
	return 2*i + 1;
}

void bubble_down(int *array, int *heap_size, int start){
	int temp = array[start];
	int i = start, compare;
	while(true){
		compare = left_child(i);
		if (compare >= *heap_size) break;
		if (compare + 1 < *heap_size && array[compare] > array[compare+1]){
			compare++;
		}
		if (temp < array[compare]) break;
		swap(array, i, compare);
		i = compare;
	}
}

int delete_min(int *array, int *heap_size){
	int ret = array[0];
	*heap_size = *heap_size - 1;
	array[0] = array[*heap_size];
	bubble_down(array, heap_size, 0);
	return ret;
}

void heapify(int *array, int *heap_size){
	for(int i = (*heap_size-1)/2; i >= 0; i--){
		bubble_down(array, heap_size, i);
	}
}

void k_smallest( int* input_array, int num_input_values, int* output_array, int k )
{
	if (k == 0) return;

	// copy input array into a temporary array -- should not contaminate input_array
	int temp[num_input_values], heap_size = num_input_values;
	for (int i = 0; i < num_input_values; i++){
		temp[i] = input_array[i];
	}

	heapify(temp, &heap_size);
	for (int i = 0; i < k; i++){
		output_array[i] = delete_min(temp, &heap_size);
	}
}
