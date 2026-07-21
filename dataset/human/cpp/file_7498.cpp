#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

    vector<ll> csum(N);
    csum[0] = A[0];
    for (int i = 1; i < N; i++) {
        csum[i] = csum[i - 1] + A[i];
    }

    ll ans = INF;
    for (int i = 0; i < N - 1; i++) {
        ll snk = csum[i];
        ll ari = csum[N - 1] - csum[i];
        chmin(ans, abs(snk - ari));
    }

    cout << ans << endl;
    return 0;
}
