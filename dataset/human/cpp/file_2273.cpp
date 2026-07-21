#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define MOD 1000000007



int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));

    int k = lower_bound(all(A), 0) - A.begin(); //1-origin
    if (k % 2 == 0) {
        rep(i, k) {
            A[i] = (-1) * A[i];
        }
    }
    else {
        rep(i, k - 1) {
            A[i] = (-1) * A[i];
        }
        if (k < N ) {
            if (A[k - 1] + A[k] < 0) {
                A[k - 1] = (-1) * A[k - 1];
                A[k] = (-1) * A[k];
            }
        }
    }
    
    ll ans = 0;
    rep(i,N) ans += A[i]; 
    cout << ans << endl;

}
