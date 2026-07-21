#include <iostream>
#include <algorithm>
using namespace std;

int main( void ) {
    ios::sync_with_stdio( false );
    long long n, num, sum = 0, k = 0, minn = 0x3f3f3f3f;
    cin >> n;
    for( int i = 0; i < n; ++i ) {
        cin >> num;
        sum += abs( num );
        if( num < 0 ) ++k;
        minn = min( abs( num ), minn );
    }
    if( k & 1 ) sum -= minn * 2;
    cout << sum << '\n';
    return 0;
}
