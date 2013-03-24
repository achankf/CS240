int interpolate(int *A, int l, int r, int k, int &numFailures){
	int i = l + ((float)(k-A[l]) / (A[r]-A[l]) * (r-l));
	int num_left = i - l+1;
	int num_right = r - i;

	if (numFailures > 31){
		throw 3;
	}
	int delta = pow(2, numFailures);

	if (num_left > num_right){
		i -= delta;
	} else if (num_right > num_left){
		i += delta;
	} else {
		return i;
	}
cout << i << endl;

	if ((i > r || i < l) && ((l+r)/2-l <= delta)){
		//cout << "BIN "<< ( (l+r) / 2-l - delta) << endl;
		return (l + r) / 2;
	}
	return i;
}
