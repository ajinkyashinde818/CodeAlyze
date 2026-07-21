#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio( false );

	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int result = 0;

	for( int i = 0; R*i <= N; ++i ) {
		for( int j = 0; G*j <= N; ++j ) {
			int x = R*i + G*j;

			if( N >= x && (N-x) % B == 0 ) {
				result += 1;
			}
		}
	}

	cout << result << endl;

	return 0;
}
