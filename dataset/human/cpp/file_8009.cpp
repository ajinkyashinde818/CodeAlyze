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

#define FOR(t,x,v) for(t x=0, v_=(v);x < v_; x++)
#define FORR(t,x,v) for(t x=(v); x >= 0; x--)

int N;
ll A[201010];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    FOR(int,x,N) cin >> A[x];

    ll total = 0; 
    FOR(int,x,N) total += A[x];

    ll ans = numeric_limits<ll>::max();
    ll acc = A[0];
    for (int j = 1; j < N; ++j) {
        ans = min(ans, abs(acc - (total - acc)));
        acc += A[j];
    }
    cout << ans << endl;
    return 0;
}
