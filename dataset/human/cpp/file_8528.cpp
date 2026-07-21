#include<bits/stdc++.h>

using namespace std;

int main() {
	long long int N, M;
	cin >> N >> M;
	vector<string>A( N ), B( M );
	for( size_t i = 0; i < N; i++ ) {
		cin >> A[i];
	}
	for( size_t i = 0; i < M; i++ ) {
		cin >> B[i];
	}
	for( size_t i = 0; i <= N - M; i++ ) {
		for( size_t j = 0; j <= N - M; j++ ) {
			bool f = true;
			for( size_t a = 0; a < M; a++ ) {
				for( size_t b = 0; b < M; b++ ) {
					if( A[i + a][j + b] != B[a][b] ) {
						f = false;
					}
				}
			}
			if( f ) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
