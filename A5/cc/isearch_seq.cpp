int interpolate(int *A, int l, int r, int k, int &numFailures){
	int i = l + ((float)(k-A[l]) / (A[r]-A[l]) * (r-l));
	int num_left = i - l+1;
	int num_right = r - i;

	if (num_left > num_right){
		i -= numFailures;
	} else if (num_right > num_left){
		i += numFailures;
	}

#if 1
	if (i > r || i < l){
		cout << "BIN " << ((l+r)/2-l - numFailures)<<endl;
		return (l + r) / 2;
	}
#endif
	return i;
}
