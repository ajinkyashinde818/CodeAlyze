#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll c = 0 , x = 0 , ans = 1000000000000000000 , a[n];
    for( int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
        c += a[i];
    }
    for( int i = 0 ; i < n ; i++ ) {
        x += a[i];
        if( i + 1 < n ) ans = min( ans , abs( c - 2 * x ) );
    }
    cout << ans << endl;
}
