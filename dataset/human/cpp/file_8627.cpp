#include <iostream>
#include <string>
using namespace std;

void read( string s[], int n )
{
	for( int i = 0; i < n; i++ ) {
		cin >> s[ i ];
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	string a[ n ], b[ m ];

	read( a, n );
	read( b, m );

	bool issame = false;
	for( int i = 0; i <= n - m and !issame; i++ ) {
		for( int j = 0; j <= n - m and !issame; j++ ) {
			
			issame = true;
			for( int x = 0; x < m; x++ ) {
				for( int y = 0; y < m; y++ ) {
					if( a[ i + x ][ j + y ] != b[ x ][ y ] ) {
						issame = false;
						break;
					}
				}
				if( !issame ) {
					break;
				}
			}
		}
	}

	cout << ( issame ? "Yes" : "No" ) << endl;
	return 0;
}
