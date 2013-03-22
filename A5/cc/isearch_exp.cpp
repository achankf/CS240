int interpolate(int *A, int l, int r, int k, int &numFailures){
	int i = l + ((float)(k-A[l]) / (A[r]-A[l]) * (r-l));
	int num_left = i - l+1;
	int num_right = r - i;

	if (numFailures > 31){
	if (num_left > num_right){
		l += pow(2, numFailures);
		if (l >= r){
			l = r - 1;
		}
	} else if (num_right > num_left){
		r -= pow(2, numFailures);
		if (r <= l){
			r = l + 1;
		}
	} else {
		return i;
	}
	}

	i = l + ((float)(k-A[l]) / (A[r]-A[l]) * (r-l));
	if (i > r) return r;
	if (i < l) return l;
	return i;
}
