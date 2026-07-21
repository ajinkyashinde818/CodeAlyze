#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int a[100005];
bool used[200005];
int main() {
    int n, m;
    cin >> n >> m;
    rep(i, m) cin >> a[i];
    reverse(a, a + m);
    rep(i, m) {
        if (!used[a[i]]) {
            cout << a[i] << endl;
            used[a[i]] = 1;
        }
    }
    rep(i, n + 1) if (i) {
        if (!used[i]) cout << i << endl;
    }
    return 0;
}
