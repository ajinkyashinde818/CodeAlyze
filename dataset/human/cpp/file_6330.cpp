#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <iomanip>
#include <math.h>
#include <time.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repf(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define repr(i, a, b) for (int i = (int)a; i > (int)b; i--)
#define all(v) (v).begin(), (v).end()
#define mp(a, b) make_pair(a, b)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 1147483600;
const ll infl = 1e18 + 5;
const char ENDL = '\n';
//cout << fixed << setprecision(17) << res << endl;
ll powmod(ll x, ll y, ll mod)
{
    ll ans = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            ans *= x;
            ans %= mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
struct COMB
{
    int L;
    vll kaijo, gyaku;
    ll mod;
    void __init__(int sz, ll md)
    {
        L = sz;
        mod = md;
        kaijo.resize(L + 1, 0);
        gyaku.resize(L + 1, 0);
        kaijo[0] = 1;
        repf(i, 1, L + 1)
            kaijo[i] = (kaijo[i - 1] * i) % mod;
        gyaku[L] = powmod(kaijo[L], mod - 2, mod);
        rep(i, L)
            gyaku[L - 1 - i] = gyaku[L - i] * (L - i) % mod;
    }
    ll powmod(ll x, ll y, ll mod)
    {
        ll ans = 1;
        while (y > 0)
        {
            if (y & 1)
            {
                ans *= x;
                ans %= mod;
            }
            x = x * x % mod;
            y >>= 1;
        }
        return ans;
    }

    ll calc(int n, int k)
    {
        if (n > L)
            return -1;
        return (((kaijo[n] * gyaku[k]) % mod) * gyaku[n - k]) % mod;
    }
    ll kai(int i)
    {
        return kaijo[i];
    }
    ll gya(int i)
    {
        return gyaku[i];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    string s;
    cin >> s;
    vii MAP(2 * n);
    rep(i,2*n){
        if (s[i]=='B')
            MAP[i] = 1;
        else
            MAP[i] = 0;
    }
    vii d(2 * n);
    d[0] = 1;
    d[2 * n - 1] = 0;
    if (MAP[0]==0 || MAP[2*n-1]==0){
        cout << 0 << ENDL;
        return 0;
    }
    //右が１で左が０
    repf(i,1,2*n-1){
        int l = i;
        if (MAP[i]){
            if (l%2){
                d[i] = 0;
            }
            else{
                d[i] = 1;
            }
        }
        else{
            if (l%2){
                d[i] = 1;
            }
            else{
                d[i] = 0;
            }
        }
    }
    ll ans = 1;
    ll now = 0;
    rep(i,2*n){
        if (d[i]){
            now++;
        }
        else{
            if (now==0){
                cout << 0 << ENDL;
                return 0;
            }
            ans = (ans * now) % mod;
            now--;
        }
    }
    if (now>0){
        cout << 0 << ENDL;
        return 0;
    }
    COMB comb;
    comb.__init__(n + 5, mod);
    ans = (ans * comb.kai(n)) % mod;
    cout << ans << ENDL;
}
