#include <numeric>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>


using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(ll i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const ll MOD = 1e9 + 7;
vi alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };


int main() {
    ll n;
    cin >> n;
    vll a(n);
    ll sa = 0;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        if (a[i] < 0)sa++;
    }
    ll sum = 0;
    rep(i, n) a[i] = abs(a[i]);
    rep(i, n) sum += a[i];
    if (sa % 2 == 0) cout << sum << endl;
    else {
        sort(a);
        cout << sum - 2*a[0] << endl;
    }
}
