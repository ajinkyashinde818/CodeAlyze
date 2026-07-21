#include <bits/stdc++.h>
using namespace std;

int main()
{
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	long long ans = 0;
	for( int r = 0; r <= N / R; r++ ) {
		for( int g = 0; g <= N / G; g++ ) {
			int n = N - (r * R + g * G);
			if( 0 <= n && n % B == 0 ) ans++;
		}
	}

	cout << ans << endl;
}
