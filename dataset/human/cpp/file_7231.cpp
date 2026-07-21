#include<iostream>
#include<algorithm>
typedef long long LL;
using namespace std;
int main() {
	int n;
	cin >> n;
	if ( n == 2 ) {
		LL x, y;
		cin >> x >> y;
		cout << abs ( x - y );
	} else {
		LL a[n];
		for ( int j = 0; j < n; j++ )
			cin >> a[j];
		LL sum1 = 0, sum2 = 0;
		for ( int j = 0; j < n; j++ )
			sum2 += a[j];
		LL minn = 1000000000000;
		for ( int j = 0; j < n-1; j++ ) {
			sum1 += a[j];
			sum2 -= a[j];
			minn = min ( minn, abs ( sum1 - sum2 ) );
		}
		cout << minn;
	}
}
