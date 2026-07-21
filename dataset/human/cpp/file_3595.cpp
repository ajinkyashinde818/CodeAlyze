#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <regex>
#include <stdexcept>
#include <unordered_set>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <time.h>
#include <numeric>
#include <complex>

using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using D = double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define fill(x, y) memset(x, y, sizeof(x))
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define rep(i, x)  for(int i = 0; i < (x); i++)
#define rrep(i, x) for(int i = (x - 1); i >= 0; i--)
#define y1 y1_1234413
#define j1 j1_235
#define y0 y0_235
#define j0 j0_256
#define fi first
#define se second
#define itn int
#define re return
#define prev PREV
#define next NEXT

#define sz(x) ((int)x.size())

const int inf = 2e9;
const ld st = 0.000001;
const ld pi = acos((ld)-1);
const int MAXN = 1e5 + 10;
#define FILENAME ""

const ll maxn = 500000 + 10;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector <ll> a;
    ll r = 0;
    bool f = true;
    ll temp = inf;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.pb(x);
        if (x == 0) {
            f = false;
        }
        else if (x < 0) {
            r++;
        }
        temp = min(temp, abs(x));
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(a[i]);
    }
    if (!f || r % 2 == 0) {
        cout << sum;
    }
    else {
        cout << sum - 2*temp;
    }
    return 0;
}
