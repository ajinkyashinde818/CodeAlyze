// {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// }}}

using ll = long long;

int N;
ll C, X[101010], V[101010];

vector<ll> vs1, vs2;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> C;
    vs1.resize(N); vs2.resize(N);
    for (int j = 0; j < N; ++j) {
        cin >> X[j] >> V[j];
    }

    vs1[0] = V[0];
    for (int j = 1; j < N; ++j) vs1[j] = vs1[j-1] + V[j];

    vs2[N-1] = V[N-1];
    for (int j = N-2; j >= 0; --j) vs2[j] = vs2[j+1] + V[j];

    vector<ll> vs1b = vs1, vs2b = vs2;

    vs1b[0] = max(0LL, vs1[0] - 2*X[0]);
    for (int j = 1; j < N; ++j) {
        vs1b[j] = max(vs1b[j-1], vs1[j] - 2*X[j]);
    }

    vs2b[N-1] = max(0LL, vs2[N-1] - 2*(C-X[N-1]));
    for (int j = N-2; j >= 0; --j) {
        vs2b[j] = max(vs2b[j+1], vs2[j] - 2*(C-X[j]));
    }

    ll ans = 0LL;

    vs1[0] = max(0LL, vs1[0] - X[0]);
    ans = max(ans, vs1[0]);
    for (int j = 1; j < N; ++j) {
        vs1[j] = max(vs1[j-1], vs1[j] - X[j]);
        ans = max(ans, vs1[j]);
    }

    vs2[N-1] = max(0LL, vs2[N-1] - (C - X[N-1]));
    ans = max(ans, vs2[N-1]);
    for (int j = N-2; j >= 0; --j) {
        vs2[j] = max(vs2[j+1], vs2[j] - (C - X[j]));
        ans = max(ans, vs2[j]);
    }

    for (int j = 0; j < N-1; ++j) {
        ans = max(ans, vs1b[j] + vs2[j+1]);
        ans = max(ans, vs1[j] + vs2b[j+1]);
    }

    cout << ans << endl;

    return 0;
}
