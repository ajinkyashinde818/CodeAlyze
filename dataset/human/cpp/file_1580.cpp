#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int main() {
    int n;
    cin >> n;
    int k = 0;
    while (k * (k - 1) / 2 < n) k++;
    if (k * (k - 1) / 2 != n){
        cout << "No" << endl;
        return 0;
    }
    VVI s(k);
    int x = 1;
    REP(i,k) REP(j,i){
        s[i].push_back(x);
        s[j].push_back(x);
        x++;
    }
    cout << "Yes" << endl << k << endl;
    REP(i,k){
        cout << s[i].size();
        for (int x : s[i]) cout << " " << x;
        cout << endl;
    }

    return 0;
}
