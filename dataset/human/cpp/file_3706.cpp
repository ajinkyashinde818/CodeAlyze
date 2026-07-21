#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, cnt_minus = 0; cin >> N;
	vector<long long> A(N);
	
	bool zero_find = false;
	
	for( int i = 0 ; i < N ; i++ ){
		cin >> A[i];
		if(A[i] == 0) zero_find = true;
		if(A[i] < 0 && !(zero_find)){
			cnt_minus++;
		}
	}
	
	long long sum = 0, tiisai = abs(A[0]);
	for( int i = 0 ; i < N ; i++){
		sum += abs(A[i]);
		tiisai = min( tiisai, abs(A[i]));
	}
	
	if(cnt_minus % 2 == 0 || zero_find)
	cout << sum << endl;
	else
	cout << sum - tiisai*2 << endl;
}
