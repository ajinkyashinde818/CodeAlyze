#include <bits/stdc++.h>
using namespace std;

int N;
int M;
char A[ 60 ][ 60 ];
char B[ 60 ][ 60 ];

bool Check( const int x, const int y )
{
int i;
int j;

	for( i = 1; i < M; i++ )
	{
		for( j = 0; j < M; j++ )
		{
			if( A[ y + i ][ x + j ] != B[ i ][ j ] )
				return false;
		}
	}

	return true;
}

int main( int argc, char *argv[] )
{
int i;
int x;
char *p;

	ios::sync_with_stdio( false );
	cin.tie( 0 );

	cin >> N;
	cin >> M;
	for( i = 0; i < N; i++ ) cin >> A[ i ];
	for( i = 0; i < M; i++ ) cin >> B[ i ];

	for( i = N - M; i >= 0; i-- )
	{
		x = 0;
		p = strstr( A[ i ], B[ 0 ] );
		while( p != NULL )
		{
			x = p - A[ i ];
			if( Check( x, i ) )
			{
				cout << "Yes" << endl;

				return 0;
			}

			x++;
			while( x > N - M ) break;

			p = strstr( A[ i ] + x, B[ 0 ] );
		}
	}

	cout << "No" << endl;

	return 0;
}
