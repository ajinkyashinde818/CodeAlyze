#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define int long long

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} SETUP;

signed main() {
    int k;
    string s;
    cin >> k >> s;
    map<char, int> mp;
    for (auto c : s) {
        mp[c]++;
    }

    int ans = 1;
    for (auto p : mp) {
        ans = (ans * (p.second + 1)) % MOD;
    }
    cout << ans - 1 << endl;
}
