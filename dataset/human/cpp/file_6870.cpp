/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>
#include <cassert>
#include <random>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
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

ll conbinationMemo[100][100];

void cmemoInit(){
    rep(i, 100){
        rep(j, 100){
            conbinationMemo[i][j] = -1;
        }
    }
}
 
ll nCr(ll n, ll r){
    if(conbinationMemo[n][r] != -1) return conbinationMemo[n][r];
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return conbinationMemo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
//-----------------------ここから-----------
int main(void){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];;

    vector<ll> rb = b;

    reverse(all(rb));

    vector<ll> same;

    rep(i, n){
        if(a[i] == rb[i]){
            same.push_back(i);
        }
    }

    //cout << same.size() << endl;

    vector<ll> ans = rb;
    ll bidx = n - 1;
    ll tmpidx = -1;
    rep(i, same.size()){
        if(ans[same[i]] == a[bidx] || ans[same[i]] == ans[bidx]){
            tmpidx = i - 1;
            break;
        }
        swap(ans[same[i]], ans[bidx]);
        bidx--;
        if(i == same.size() - 1){
            tmpidx = i;
        }
    }
    ll fidx = 0;
    for(ll i = (ll)same.size() - 1; i > tmpidx; i--){
        swap(ans[same[i]], ans[fidx]);
        fidx++;
    }
    bool ok = true;
    rep(i, n){
        if(ans[i] == a[i]) ok = false;
    }

    if(ok){
        cout << "Yes" << endl;
        rep(i, n) cout << ans[i] << " ";
        cout << endl;
    } else {
        cout << "No" << endl;
    }

}
