#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const int INF = 1 << 28;
const ll MOD = 1'000'000'007;
template <class T>
bool chmax(T &a, const T &b) { return (a < b) ? (a = b, 1) : 0; }
template <class T>
bool chmin(T &a, const T &b) { return (b < a) ? (a = b, 1) : 0; }

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    ll ret;
    for (int i = 0; i <= N / R; ++i) {
        for (int j = 0; j <= N / G; ++j) {
            ll rest = N - i * R - j * G;
            if (0 <= rest && rest % B == 0)
                ret++;
        }
    }
    cout << ret << endl;
    return 0;
}
