#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, c;
    cin >> n >> c;
    vector<pair<long long, long long> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<long long> left(n), right(n);
    long long ans = 0;
    left[0] = a[0].second;
    ans = max(ans, a[0].second - a[0].first);
    for (int i = 1; i < n; i++) {
        left[i] = left[i-1] + a[i].second;
        ans = max(ans, left[i] - a[i].first);
    }
    right[n-1] = a[n-1].second;
    ans = max(ans, a[n-1].second - (c - a[n-1].first));
    for (int i = n-2; i >=0; i--) {
        right[i] = right[i+1]+a[i].second;
        ans = max(ans, right[i] - (c - a[i].first));
    }
    vector<long long> leftm(n), rightm(n);
    leftm[0] = max((long long)0,a[0].second - a[0].first);
    rightm[n-1] = max((long long)0, a[n-1].second - (c - a[n-1].first));
    for (int i = 1; i < n; i++) {
        leftm[i] = max(leftm[i-1], left[i] - a[i].first);
    }
    for (int i = n-2; i >= 0; i--) {
        rightm[i] = max(rightm[i+1], right[i] - (c - a[i].first));
    }
    for (int i = 0 ; i < n-1; i++)  {
        ans = max(ans, left[i] - 2*a[i].first + rightm[i+1]);
    }
    for (int i = 1; i < n; i++) {
        ans = max(ans, right[i] - 2*(c - a[i].first) + leftm[i-1]);
    }
    cout << ans;
}
