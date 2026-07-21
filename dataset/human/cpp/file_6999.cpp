#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    range(i, n) cin >> a[i];
    range(i, n) cin >> b[i];
    set<pair<int, pair<int, int>>> s1, s2;
    vector<int> cntcol(n+1);
    for(int i =0, j = 0; i < n; i = j) {
        while(a[j] == a[i]) j++;
        s1.insert({i-j, {i, j}});
        cntcol[a[i]] = i - j;
    }
    vector<pair<int, int>> v(n+1);
    for(int i =0, j = 0; i < n; i = j) {
        while(b[j] == b[i]) j++;
        v[b[i]] = {i, j};
        s2.insert({cntcol[b[i]] + i - j, {i, j}});
    }
    vector<int> ans(n);
    range(i, n) {
        auto p1 = *s1.begin();
        s1.erase(s1.begin());
        auto p2 = *s2.begin();
        s2.erase(s2.begin());
        if (b[p2.second.first] == a[p1.second.first]) {
            if (s2.empty()) {
                cout << "No\n";
                return;
            }
            auto p3 = *s2.begin();
            s2.erase(s2.begin());
            s2.insert(p2);
            p2 = p3;
        }
        ans[p1.second.first] = b[p2.second.first];
        int col = a[p1.second.first];
        if (v[col].second - v[col].first) {
            s2.erase({p1.first + v[col].first - v[col].second, v[col]});
            s2.insert({p1.first + v[col].first - v[col].second + 1, v[col]});
        }
        v[b[p2.second.first]].first++;
        p2.second.first++;
        p1.first++;
        p1.second.first++;
        p2.first++;
        if (p1.first) s1.insert(p1);
        if (p2.second.second - p2.second.first) s2.insert(p2);
    }
    cout << "Yes\n";
    range(i, n) cout << ans[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
