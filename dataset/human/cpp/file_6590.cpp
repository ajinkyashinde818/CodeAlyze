#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 228228
#define MOD 1000000007
ll x, y, n, m, k;
ll a[MAXN];
vector<ll> f, g;
string s;
int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < 2*n; i++) {
        ll x = 1;
        if (s[i] == 'B') {
            x = 0;
        }
        if (i % 2 == 1) {
            x ^= 1;
        }
        a[i] = x;
    }
    ll x = 0;
    ll ans = 1;
    for (int i = 0; i < 2 * n; i++) {
        if (a[i] == 0) {
            x++;
        } else {
            if (x == 0) {
                cout << 0 << endl;
                return 0;
            }
            ans = ans * x % MOD;
            x--;
        }
    }
    if (x != 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        ans = ans * i % MOD;
    }
    cout << ans << endl;

    return 0;
}
