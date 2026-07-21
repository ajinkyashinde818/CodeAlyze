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
#include <unordered_set>



using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)



















int main(){
    ll r, g, b, n;
    cin >> r >> g >> b >> n;
    ll ans = 0;
    REP(i, n + 1){
        REP(j, n + 1){
            ll B = n - r * i - g * j;
            if(B >= 0 && B % b == 0){
                ans++;
                // cerr << i << " " << j << " " << ans << endl;
            }
        }
    }
    cout << ans << endl;
}
