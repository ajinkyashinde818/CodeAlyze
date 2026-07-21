#include <algorithm>
#include <array>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<ld>> vvd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const ll MOD = 1e9 + 7;
void add(ll& x, ll y) { x += y; if (x >= MOD) x -= MOD; }
void take(ll& x, ll y) { x -= y; if (x < 0) x += MOD; }

ll sum(ll a, ll b) { add(a, b); return a; }
ll sub(ll a, ll b) { take(a, b); return a; }
ll mul(ll x, ll y) { return (x * y) % MOD; }

ll fact(ll a) {
    ll ans = 1;
    for (ll i = 2; i <= a; ++i) {
        ans *= i;
        ans %= MOD;
    }
    ans %= MOD;
    return ans;
}

ll ans = 1;
void foo(ll x) { ans = mul(ans, x); }

int main() {
    cout << setprecision(30);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll n;
    string s;
    cin >> n >> s;

    ll started = 0;
    ll curr = 1;
    for (int i = 0; i < 2 * n; ++i) {
        ll t = s[i] == 'W' ? 0 : 1;
        if (t == curr) {
            ++started;
        } else {
            if (started <= 0) {
                cout << 0 << endl;
                return 0;
            }
            foo(started--);
        }
        curr = 1 - curr;
    }
    if (started != 0) {
        cout << 0 << endl;
        return 0;
    }

    foo(fact(n));
    cout << ans << endl;

    return 0;
}
