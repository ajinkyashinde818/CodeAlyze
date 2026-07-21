// https://atcoder.jp/contests/abc125/tasks/abc125_c

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF (1e9)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
// int gcd(long a, long b) { return b ? gcd(b, a % b) : a; }
// int lcm(long a, long b) { return a * b / gcd(a, b); }

// マイナスの個数が奇数の場合、右端か左端の片方がマイナスになり、他はプラス
// 上記以外の場合、全部プラス
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, ans = 0, minusCnt = 0, minv = INF;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += abs(a[i]);
        minv = min(minv, abs(a[i]));
        if (a[i] < 0) {
            minusCnt++;
        }
    }

    if (minusCnt % 2 != 0) {
        ans -= 2 * minv;
    }

    cout << ans << endl;

    return 0;
}
