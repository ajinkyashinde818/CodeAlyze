#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a[0];
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    vector<ll> b(n-1);
    for(int i = 0; i < n-1; i++) {
        b[i]=abs(a[i]-(a[n-1]-a[i]));
    }
    sort(b.begin(),b.end());
    cout << b[0] << endl;

    return 0;
}
