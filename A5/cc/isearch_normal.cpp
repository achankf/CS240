int interpolate(int *A, int l, int r, int k, int &numFailures){
	int i = l + ((float)(k-A[l]) / (A[r]-A[l]) * (r-l));
	if (i > r) return r;
	if (i < l) return l;
	return i;
}
