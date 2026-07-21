#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m = 1e18;
    cin >> n;
    long long a[n + 1], s[n + 1];
    s[0] = 0;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (long long i = 1; i < n; i++)
        m = min(m, abs(s[n] - s[i] * 2));
    cout << m;
}
