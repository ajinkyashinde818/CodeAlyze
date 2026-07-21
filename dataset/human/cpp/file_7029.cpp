#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INFL = 1e18;
const int INF = 1000000007;
const ld PI = acos(-1);
const ld EPS = 1e-13;
const ll MOD = 1000000007;

void add(ll& a, ll b) {
    a += b;
    while (a >= MOD) {
        a -= MOD;
    }
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll todeg(ll x, ll d) {
    if (d < 0LL) {
        d += MOD - 1;
    }
    if (d == 0LL) {
        return 1LL;
    }
    ll ans = todeg(x, d / 2LL);
    mul(ans, ans);
    if (d % 2 == 1) {
        mul(ans, x);
    }
    return ans;
}

vector<ll> fact;
vector<ll> rfact;

void prep(int n) {
    fact.assign(n + 1, 1);
    rfact.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
    }
    rfact[n] = todeg(fact[n], -1);
    for (int i = n - 1; i >= 0; --i) {
        rfact[i] = rfact[i + 1];
        mul(rfact[i], i + 1);
    }
}

ll C(int n, int k) {
    ll ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n, 0), ca(n + 1, 0), cb(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++ca[a[i]];
    }
    for (int i = 0; i < n; ++i) {
        int vb;
        cin >> vb;
        ++cb[vb];
    }

    for (int i = 1; i <= n; ++i) {
        if (ca[i] + cb[i] > n) {
            cout << "No\n";
            return 0;
        }
    }

    priority_queue<int> inds, sind, used, ucur;
    for (int i = 0; i < n; ++i) {
        inds.push(i);
    }

    for (int v = 1; v <= n; ++v) {
        int cv = cb[v];
        while (cv > 0 && !inds.empty()) {
            if (a[inds.top()] != v) {
                b[inds.top()] = v;
                --cv;
                ucur.push(inds.top());
                inds.pop();
            }
            else {
                sind.push(inds.top());
                inds.pop();
            }
        }
        while (cv > 0) {
            b[sind.top()] = b[used.top()];
            b[used.top()] = v;
            ucur.push(used.top());
            ucur.push(sind.top());
            used.pop();
            sind.pop();
            --cv;
        }
        while (!sind.empty()) {
            inds.push(sind.top());
            sind.pop();
        }
        while (!ucur.empty()) {
            used.push(ucur.top());
            ucur.pop();
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }

    return 0;
}
