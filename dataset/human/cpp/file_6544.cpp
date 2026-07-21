#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
// constexpr ll MOD = 998244353;
constexpr ll MOD = 1000000007;

// struct UnionFind {
//     vector<int> par;
    
//     UnionFind(int N): par(N) {
//         for (int i=0;i<N;i++) par[i] = i;
//     }

//     int root(int x) {
//         if (par[x] == x) return x;
//         else return par[x] = root(par[x]);
//     }

//     void unite(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         if (rx == ry) return;
//         par[rx] = ry;
//     }

//     bool same(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         return rx == ry;
//     }
// };

int main(void) {
    ll N;
    string S;
    cin >> N >> S;
    vector<int> RL(2LL*N,0);

    for (ll i=0;i<2LL*N;i++) {
        ll j = 2*N-i-1;
        if (j%2) {
            if (S[i] == 'W') S[i] = 'B';
            else S[i] = 'W';
        }
    }
    for (ll i=0;i<2LL*N;i++) {
        if (S[i] == 'B') RL[i]++;
    }
    if (count(RL.begin(), RL.end(), 1) != N || RL[0] == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1LL, X = 0LL;
    for (ll i=0;i<2LL*N;i++) {
        if (!RL[i]) X++;
        else {
            ans = ans * X-- % MOD;
        }
    }
    for (ll i=1;i<=N;i++) {
        ans = ans * i % MOD;
    }
    cout << ans << endl;

    return 0;
}
