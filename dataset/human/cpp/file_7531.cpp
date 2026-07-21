#include <bits/stdc++.h>
using namespace std;

int N;
long long A[200000];

int main(){
	long long sum = 0, small = LLONG_MAX;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int val;
		scanf("%d", &val);
		sum += val;
		A[i] = sum;
	}
	for(int i = 1; i < N; i++){
		long long a = A[N - 1] - A[i - 1];
		small = min(small, abs(a - A[i - 1]));
	}
	printf("%lld\n", small);
	return 0;
}
