#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)









int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0, cnt = 0;
    REP(i, n){
        cin >> a[i];
        sum += abs(a[i]);
        if(a[i] < 0) cnt++;
    }
    if(cnt % 2 == 1){
        ll mn = INF;
        REP(i, n){
            mn = min(mn, abs(a[i]));
        }
        sum -= 2 * mn;
    }
    cout << sum << endl;
}
