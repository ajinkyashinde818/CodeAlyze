#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1LL << 60;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-6;
using pii = std::pair<int, int>;
using pLL = std::pair<long long, long long>;
using ll = long long;
#define SORT(v) std::sort(v.begin(), v.end())
#define rSORT(v) std::sort(v.begin(), v.end(),std::greater<int>())
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) {
        return b;
    }
    return gcd(b, a%b);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += abs(a[i]);
    }
    int count = 0;
    ll mn = LINF;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= 0) count++;
        mn = min(mn, abs(a[i]));

    }
    
    if (count % 2 == 0) {
        cout << ans << endl;
    }
    else {
        ans -= 2 * mn;
        cout << ans << endl;
    }
    return 0;
}
