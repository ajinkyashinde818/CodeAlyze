#include <bits/stdc++.h>
using namespace std;

string incl( vector<string>& A, vector<string>& B, int n, int m ) {
	bool result = false;

	for( int i = 0; i < n-m+1; ++i ) {
		for( int j = 0; j < n-m+1; ++j ) {
			bool matched = true;

			for( int p = 0; p < m; ++p ) {
				for( int q = 0; q < m; ++q ) {
					if( A[i+p][j+q] != B[p][q] ) {
						matched = false;
						break;
					}
				}

				if( !matched ) { break; }
			}

			if( matched ) {
				result = true;
				break;
			}
		}

		if( result ) { break; }
	}

	return result ? "Yes" : "No";
}

int main() {
	ios_base::sync_with_stdio( false );

	int N, M;
	cin >> N >> M;

	vector<string> A( N );
	vector<string> B( M );
	for( auto& v: A ) { cin >> v; }
	for( auto& v: B ) { cin >> v; }

	cout << incl( A, B, N, M ) << endl;
}
