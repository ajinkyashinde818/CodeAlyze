#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M; cin >> N >> M;
	vector<string> A(N), B(M);
	for( string &k : A )cin >> k;
	for( string &k : B )cin >> k;
	for( int i = 0; i < N - M + 1; i++ ){
		for( int j = 0; j < N - M + 1; j++ ){ // kokomade heikouidou
			for( int k = 0; k < M; k++ ){
				for( int l = 0; l < M; l++ ){
					if( A[k+i][l+j] != B[k][l]) goto end;
				}
			}
			cout << "Yes" << endl;
			return 0;
			end:;
		}
	}
	cout << "No" << endl;
}
