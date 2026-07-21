#include <algorithm>
#include <bitset>
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
    ll N;
    string S;
    cin >> N >> S;

    vector<ll> alph(26);

    rep(i, N) alph[S[i] - 'a']++;

    sort(alph.begin(), alph.end(), greater<ll>());

    alph.erase(remove(alph.begin(), alph.end(), 0), alph.end());

    // repv(alph) cout << *it << " ";
    // cout << endl;

    ll ans = 1;
    rep(i, alph.size()) {
        ans *= (alph[i] + 1);
        ans = ans % MOD;
    }
    cout << ans - 1 << endl;

    // for (ll bit = 0; bit < (1 << alph.size()); bit++) {
    //     ll prod = 1;
    //     ll cnt = 0;
    //     for (ll i = 0; i < alph.size(); i++) {
    //         if (bit & (1 << i)) {
    //             cnt++;
    //             prod *= alph[i];
    //         }
    //     }

    //     if (cnt > 0) ans += (prod % MOD);

    //     // cout << showbase;
    //     // cout << bitset<10>(bit);
    //     // cout << noshowbase;
    //     // cout << ":" << prod << ", ans:" << ans << endl;
    // }
    // cout << ans << endl;

    return 0;
}
