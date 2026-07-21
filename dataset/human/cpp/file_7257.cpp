#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[200000];
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    long long x[200000] = {}, y[200000] = {};
    long long xs = 0, ys = 0;
    for(int i=0; i<n; i++){
        xs += a[i];
        x[i] = xs;
        ys += a[n-i];
        y[n-i] = ys;
    }

    long long ans = 200000000000000;
    for(int i=0; i<n-1; i++){
        ans = min(ans, abs(x[i] - y[i+1]));
    }

    cout << ans << endl;

    return 0;
}
