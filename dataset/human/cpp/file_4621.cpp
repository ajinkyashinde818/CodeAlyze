#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <random>
#include <ctime>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <queue>
#include <deque>
#include <list>
#include <stack>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ld long double
#define ull unsigned long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define fast_io cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
ld eps = (ld)1 / 1e15;
ll inf = 1e18, mod2 = 998244353, mod1 = 1e9 + 7;
ll sqr(ll a) { return a * a; }
ll qb(ll a) { return a * a * a; }
ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }
ll binpow(ll a, ll b, ll mod) { return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod : sqr(binpow(a, b / 2, mod)) % mod) : 1; }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //freopen("race.in", "r", stdin), freopen("race.out", "w", stdout);
    fast_io;
    ll n, r;
    cin >> n >> r;
    cout << (n >= 10 ? r : r + 100 * (10 - n));
    return 0;
}
