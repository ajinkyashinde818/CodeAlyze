// Nurbakyt Madibek
// Look at my code! IT'S AWESOME

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <bitset>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) (int)((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;
typedef pair < ll, ll > pl;

const int inf = (int)1e9 + 123;
const ll infl = (ll)1e18 + 123;
const double eps = 1e-9;

const int MAX_N = (int)1e5 + 5;
const int mod = (int)1e9 + 7;

int n;
int a[MAX_N], b[MAX_N];

vector < int > g[MAX_N];

bool u[MAX_N];

pi dfs(int v) {
    pi res = mp(1, sz(g[v]));
    u[v] = 1;
    for (auto to : g[v])
        if (!u[to]) {
            pi now = dfs(to);
            res.f += now.f, res.s += now.s;
        }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    a[0] = b[0] = 0;
    for (int i = 1; i <= n; i++)
        a[0] ^= a[i], b[0] ^= b[i];
    multiset < int > f, s;
    for (int i = 0; i <= n; i++)
        f.insert(a[i]), s.insert(b[i]);
    if (f != s) {
        puts("-1");
        return 0;
    }
    vector < int > q;
    for (int i = 0; i <= n; i++)
        q.pb(a[i]);
    sort(q.begin(), q.end());
    q.resize(unique(q.begin(), q.end()) - q.begin());
    for (int i = 0; i <= n; i++) {
        a[i] = (int)(lower_bound(q.begin(), q.end(), a[i]) - q.begin());
        b[i] = (int)(lower_bound(q.begin(), q.end(), b[i]) - q.begin());
    }
//    for (int i = 0; i <= n; i++)
//        cout << a[i] << ' ';
//    cout << endl;
//    for (int i = 0; i <= n; i++)
//        cout << b[i] << ' ';
//    cout << endl;
    for (int i = 0; i <= n; i++) {
        if (a[i] != b[i]) {
            g[a[i]].pb(b[i]);
            g[b[i]].pb(a[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (!u[a[i]]) {
            pi now = dfs(a[i]);
            now.s /= 2;
            if (now.f == 1)
                continue;
            if (i != 0)
                ans += now.s + 1;
            else {
                if (a[i] != b[i])
                    ans += now.s - 1;
                else
                    ans += now.s;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
