int interpolate(int *A, int l, int r, int k, int &numFailures){
	int i = l + ((float)(k-A[l]) / (A[r]-A[l]) * (r-l));
	int num_left = i - l+1;
	int num_right = r - i;

cout << "old l:" <<l << " r:" << r << endl;
	if (num_left > num_right){
		l += numFailures;
		if (l >= r){
			l = r - 1;
		}
	} else if (num_right > num_left){
		r -= numFailures;
//cout << r << " " << numFailures << endl;
		if (r <= l){
			r = l + 1;
		}
	}

	i = l + ((float)(k-A[l]) / (A[r]-A[l]) * (r-l));
cout << "i:"<<i  << " l:"<< l << " r:" << " num_left:" << num_left << " num_right:"<< num_right<< endl;

	if (i > r) return r;
	if (i < l) return l;
	return i;
}
