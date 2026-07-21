// https://atcoder.jp/contests/agc031/tasks/agc031_a

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

#define EPS (1e-7)
#define INF (1e9)
#define MODI (1000000007)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOREACH(x, a) for (const auto &(x) : (a))
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

// long gcd(long a, long b) { return b ? gcd(b, a % b) : a; }
// long lcm(long a, long b) { return a * b / gcd(a, b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str;
    cin >> n;
    cin >> str;
    map<char, int> mp;

    // 文字に重複がなければ、n^(文字数)
    // 文字に重複があれば、abcaの場合はaはなし、先頭、末尾の3通り、bとcは有無の2通り
    for (const auto &x : str) {
        // 見つからない場合
        if (mp.find(x) == mp.end()) {
            mp[x] = 1;
        } else {
            mp[x]++;
        }
    }
    long ans = 1;
    for (const auto &x : mp) {
        ans = (ans * (x.second + 1)) % MODI;
    }

    // 0文字を除外
    cout << ans - 1 << endl;

    return 0;
}
