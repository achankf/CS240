
int delta(int numFailures){
	return numFailures;
}

int interpolate(int *A, int l, int r, int k){
	return l + ((float)(k-A[l]) / (A[r]-A[l]) * (r-l));
}
