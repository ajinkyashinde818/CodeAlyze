#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

ll fact(ll n, ll mod) {
    ll val = 1;
    for (int i = 1; i <= n; i++) {
        val = val * i % mod;
    }
    return val;
}

int main() {
    ll n, mod = 1e9 + 7;
    cin >> n;
    string s;
    vector<bool> t;
    t.push_back(0);
    cin >> s;
    if (s[0] == 'W' || s[2*n - 1] == 'W') {
        cout << 0 << endl;;
        return 0;
    }

    ll ans = 1, l = 0;
    for (int i = 1; i < 2 * n; i++) {
        if (s[i] != s[i - 1]) {
            t.push_back(t[i - 1]);
        }
        else t.push_back(t[i - 1] ^ 1);
    }
    for (int i = 0; i < 2*n; i++) cerr << t[i];
    cerr << endl;
    for (int i = 0; i < 2 * n; i++) {
        if (t[i] == 0) l++;
        else {
            ans = ans * l % mod;
            l--;
        }
        if (l < 0) {
            cout << 0 << endl;;
            return 0;
        }
    }
    cout << (l == 0 ? ans * fact(n, mod) % mod : 0) << endl;
    
    
}
