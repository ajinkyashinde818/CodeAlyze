#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<string> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    rep(i, N - M + 1) {
        rep(j, N - M + 1) {
            bool flg = true;
            rep(k, M) {
                rep(m, M) {
                    if (A[i + k][j + m] != B[k][m]) {
                        flg = false;
                    }
                }
            }

            if (flg) {
                // cout << "Yes: (" << i << ", " << j << ")" << endl;
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
