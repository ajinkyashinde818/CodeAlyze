#include<bits/stdc++.h>
using namespace std;

signed main() {

    int ans = 0;
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    for ( int i = 0; i*r <= n; i++ ) {
        for ( int j = 0; j*g <= n; j++ ) {
            if ( i*r+j*g > n ) continue;
            int N = n-i*r-j*g;
            if ( N % b == 0 ) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
