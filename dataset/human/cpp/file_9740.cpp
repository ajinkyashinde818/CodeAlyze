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


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)





int main() {
    ll n;
    string s;
    cin >> n >> s;
    ll cnt[26] = {};
    REP(i, n){
        cnt[s[i] - 'a']++;
    }
    ll ans = 1;
    REP(i, 26){
        ans *= cnt[i] + 1;
        ans %= MOD;
    }
    cout << (ans - 1 + MOD) % MOD << endl;
}
