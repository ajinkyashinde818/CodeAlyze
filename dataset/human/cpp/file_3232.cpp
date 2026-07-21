#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	int N; cin >> N;
	vector<int> A;

	A.resize(N);
	for(int i = 0; i < N; ++i) cin >> A[i];

	long absmin = 1000000000;
	long sum = 0;
	long minus = 0, zero = 0;
	for(int i = 0; i < N; ++i){
		sum += abs(A[i]);

		if(absmin > abs(A[i])) absmin = abs(A[i]);
		if(A[i] < 0) minus++;
		if(A[i] == 0) zero = 1;
	}

	if(zero == 1) cout << sum << endl;
	else if(minus % 2 == 0) cout << sum << endl;
	else if(minus % 2 == 1) cout << sum - absmin * 2 << endl;

	return 0;
}
