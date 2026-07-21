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
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define Yes(condition) if(condition){ cout << "Yes" << '\n'; }else{ cout << "No" << '\n'; }
#define YES(condition) if(condition){ cout << "YES" << '\n'; }else{ cout << "NO" << '\n'; }
#define yes(condition) if(condition){ cout << "yes" << '\n'; }else{ cout << "no" << '\n'; }





int main() {
    ll n;
    cin >> n;
    ll sum = 0, h = 0;
    bool ok = false;
    REP(i, 10000){
        sum += (i + 1);
        if(sum == n){
            ok = true;
            h = i + 2;
            break;
        }
    }
    
    if(!ok){
        cout << "No" << endl;
        return 0;
    }
    
    ll w = h - 1;
    vector<vector<ll>> ans(h, vector<ll>(w));
    ll v = 1;
    REP(i, w){
        for(ll j = i; j < w; j++){
            ans[i][j] = v;
            ans[j + 1][i] = v;
            v++;
        }
    }
    
    cout << "Yes" << '\n';
    cout << h << '\n';
    REP(i, h){
        cout << ans[i].size() << ' ';
        REP(j, w){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
