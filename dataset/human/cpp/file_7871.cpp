#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a[200000];
    long long int allsum = 0, partsum = 0;
    long long int ans = 1e10;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        allsum += a[i];
    }

    if(n == 2) {
        cout << abs(a[0] - a[1]) << endl;
        return 0;
    }
    
    partsum += a[0];

    for(int i = 1; i < n - 1; ++i) {
        ans = min(ans, abs(partsum - (allsum - partsum))); 
        partsum += a[i];
    }
    cout << ans << endl;
    return 0;
}
