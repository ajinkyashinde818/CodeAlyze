#include<iostream>
#include<vector>
using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> s(N+1);
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        s[i+1] = s[i] + a;
    }

    ll ans = 1e18 + 1;
    for(int i = 1; i <= N-1; i++) {
        ans = min(ans, abs(s[i] - (s[N] - s[i])));
    }

    cout << ans << endl;

    return 0;
}
