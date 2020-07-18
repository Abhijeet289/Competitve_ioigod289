// The following techniques come handy when we are using vector of pair of something even more messed up.
// Ex. vector < pair <int,int> > vec;
// And now we want to sort the vector according to the second coordinate.(If they are same then according to first).

bool cmp(const pair <int,int> &a, const pair <int,int> &b){
	if(a.second==b.second)
		return a.first<b.first;
	return a.second<b.second;
}

// Suppose we have a struct.
struct demo{
	int q1;
	int q2;
	char q3;
};

bool cmp(struct demo &a, struct demo &b){
	return a.q2<b.q2;
}
