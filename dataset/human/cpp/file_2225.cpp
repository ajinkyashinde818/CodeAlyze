#include <bits/stdc++.h>
using namespace std;

long long N, A[100010], neg=0, mini=1000000001, sum=0;

int main () {
	cin >> N;
	for(int i=1; i<=N; i++) {
		cin >> A[i];
		mini = min(mini, abs(A[i]));
		sum += abs(A[i]);
		if (A[i] < 0) neg++;
	}
	if (neg%2==0)
		cout << sum << endl;
	else
		cout << sum-2*mini << endl;	
	return 0;
}
