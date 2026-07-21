#include <bits/stdc++.h>
using namespace std;


int B[ 500 ][ 500 ];

int main()
{
int i;
int j;
int N;
int a;
int k;
int iNew;
int A;

	ios::sync_with_stdio( false );
	cin.tie( 0 );

	cin >> N;

	k = N * 2;
	for( a = 1; a < 447; a++ )
	{
		if( a * ( a + 1 ) == k ) break;
	}

	if( a == 447 )
	{
		cout << "No" << endl;

		return 0;
	}

	for( k = 0; k < a; k++ )
	{
		B[ 0 ][ k ] = k + 1;
	}

	iNew = a + 1;
	A = 0;
	for( k = 1; k <= a; k++ )
	{
		for( i = 0; i < k; i++ )
		{
			B[ k ][ i ] = B[ i ][ A ];
		}

		A++;
		for( ; i < a; i++ )
		{
			B[ k ][ i ] = iNew;
			iNew++;
		}
	}

	cout << "Yes" << endl;
	cout << a + 1 << endl;

	for( k = 0; k <= a; k++ )
	{
		cout << a << " " << B[ k ][ 0 ];
		for( i = 1; i < a; i++ )
		{
			cout << " " << B[ k ][ i ];
		}

		cout << endl;
	}

	return 0;
}
