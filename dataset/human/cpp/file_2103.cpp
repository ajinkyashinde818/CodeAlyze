#include<bits/stdc++.h>
using namespace std;

long long N;
long long A[100005];

int main(){
	cin >> N;
	long long neg_count = 0;
	for(long long i = 0; i < N; i++){
		cin >> A[i];
		if(A[i] < 0){
			neg_count++;
		}
	}

	long long count = 0;
	if(neg_count % 2 == 0){
		for(long long i = 0; i < N; i++){
			count += abs(A[i]);
		}
	} else {
		long long mini = INT_MAX;
		for(long long i = 0; i < N; i++){
			count += abs(A[i]);
			mini = min(mini, abs(A[i]));
		}
		count -= 2*mini;
	}
	cout << count << endl;
}
