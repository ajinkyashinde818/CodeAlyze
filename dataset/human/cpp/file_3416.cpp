#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <long long int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    long long int ans = 0, mn = abs(a[0]), odd = 0;
    for (int i=0; i<n; i++){
        ans += abs(a[i]);
        if (a[i] < 0) odd ++;
        mn = min(mn, abs(a[i]));
    }
    if (odd & 1) ans -= 2*mn;
    cout << ans;
    return 0;
}
