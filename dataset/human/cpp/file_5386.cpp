#include <iostream>
using namespace std;

int main ( void )
{
	int n, r, dis;
	cin >> n >> r;

	if ( ( n < 1 ) && ( 100 < n ) ){
		cout << "ERROR!\n";
		return 0;
	}

	if ( ( r < 0 ) && ( 4111 < r ) ){
		cout << "ERROR!\n";
		return 0;
	}

	if ( n >= 10 ){
		cout << r << "\n";
	} else {
		dis = r + ( 100 * ( 10 - n ) );
		cout << dis << "\n";
	}

	return 0;
}
