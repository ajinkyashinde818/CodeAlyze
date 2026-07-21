#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	long long ans = 0;
	int cnt = 0;
	for( int i = 0; i < N; i++ ) {
		ans += abs( A[i] );
		if( A[i] < 0 ) cnt++;
	}
	if( cnt % 2 ) {
		long long mi = INT64_MAX / 2;
		for( int i = 0; i < N; i++ ) {
			if( abs( A[i] ) < mi ) mi = abs( A[i] );
		}
		ans -= mi * 2;
	}

	cout << ans << endl;
}
