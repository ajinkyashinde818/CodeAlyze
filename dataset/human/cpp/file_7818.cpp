/*
これを入れて実行
g++ code.cpp
./a.out
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;

bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}

ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll nCm(ll n, ll m){
    if(m == 0 || m == n){
        return 1;
    } else if(m == 1){
        return n;
    }
    return (nCm(n - 1, m) + nCm(n - 1, m - 1));
}

//-----------------------ここから-----------


int main(void){
    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    vector<ll> l(n);
    l[0] = a[0];
    for(ll i = 1; i < n; i++){
        l[i] = l[i - 1] + a[i];
    }

    vector<ll> r(n);
    r[n - 1] = a[n - 1];
    for(ll i = n - 1; i >= 0; i--){
        r[i] = r[i + 1] + a[i];
    }

    reverse(r.begin(), r.end());

    ll ans = INF;
    for(ll i = 0; i < n - 1; i++){
        ans = min(ans, abs(l[i] - r[n - 2 - i]));
    }

    cout << ans << endl;
}
