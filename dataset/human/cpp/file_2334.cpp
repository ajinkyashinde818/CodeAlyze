#include <iostream>
#include <array>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;
using ll = long long;

ll N;
vector<ll> A;

void input() {
    cin >> N;
    A.resize(N);
    for (auto& a : A) cin >> a;
}

ll solve() {
    ll cminus = 0;
    for (auto& a : A) if (a < 0) {
        cminus++;
        a = -a;
    }
    sort(A.begin(), A.end());
    ll ans = 0;
    for (auto a : A) ans += a;
    if (cminus % 2)
        ans -= A[0]*2;
    return ans;
}

int main() {
    input();
    cout << solve() << endl;
//    solve();

    return 0;
}
