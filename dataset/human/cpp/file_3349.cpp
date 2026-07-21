#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int64_t> a( n ), b( n );
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	int c = 0;
	for ( int i = 0; i < n; i++ ) {
		b[i] = a[i] < 0 ? -a[i] : a[i];
		if ( a[i] < 0 ) c++;
	}
	sort( b.begin(), b.end() );
	if ( c % 2 ) b[0] = -b[0];
	int64_t r = 0;
	for ( int i = 0; i < n; i++ ) r += b[i];
	cout << r << endl;
	return 0;
}
