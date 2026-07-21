#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, C;
    cin >> N >> C;
    vector<ll> X(N+2), V(N+2);
    X[0] = 0;
    X[N+1] = C;
    V[0] = 0;
    V[N+1] = 0;
    for ( int i = 1; i <= N; i++ ) {
        cin >> X[i] >> V[i];
    }
    vector<ll> R1(N+2), R2(N+2), L1(N+2), L2(N+2), R2M(N+2), L2M(N+2);
    for ( int i = 1; i <= N; i++ ) {
        R1[i] = R1[i-1] + V[i] - (X[i]-X[i-1]);
        R2[i] = R2[i-1] + V[i] - (X[i]-X[i-1]) * 2;
        R2M[i] = max(R2M[i-1], R2[i]);
    }
    for ( int i = N; i >= 1; i-- ) {
        L1[i] = L1[i+1] + V[i] - (X[i+1]-X[i]);
        L2[i] = L2[i+1] + V[i] - (X[i+1]-X[i]) * 2;
        L2M[i] = max(L2M[i+1], L2[i]);
    }
    ll ans = 0;
    for ( int i = 0; i <= N; i++ ) {
        if ( ans < R1[i] ) ans = R1[i];
        ll u = R1[i] + L2M[i+1];
        if ( ans < u ) ans = u;
    }
    for ( int i = N; i >= 1; i-- ) {
        if ( ans < L1[i] ) ans = L1[i];
        ll u = L1[i] + R2M[i-1];
        if ( ans < u ) ans = u;
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}
