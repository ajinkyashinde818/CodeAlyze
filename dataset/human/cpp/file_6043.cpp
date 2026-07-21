#include <iostream>
#include <vector>
#include <string.h>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <stack>
#include <iomanip>
#include <climits>
#include <complex>
#include <cmath>
#define fi first
#define se second
#define th second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef multiset<ll, greater<ll>>::iterator iit;
typedef pair<iit, iit> pvi;
typedef complex<double> cd;

const int maxN = 1e5 + 3, MOD = 1e9 + 9, LG = 21;
//NOTE: maxN>2^LG must be held, remember maxN is twice ur biggest polynom
/*
 HAB
 G C
 FE
 D*/
ll tot, C;
int n;

ll place[maxN], cost[maxN], best[maxN];

void solve(){
    ll sum = 0;
    for(int i = n - 1; i >= 0; i--){
        sum += cost[i];
        best[i] = sum - (C - place[i]);
        if(i < n - 1) best[i] = max(best[i], best[i + 1]);
    }
    
    sum = 0;
    
    for(int i = 0; i < n; i++){
        sum += cost[i];
        
        if(i + 1 < n) tot = max(tot, sum + best[i + 1] - place[i] * 2);
        tot = max(tot, sum - place[i]);
        
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> C;
    
    for(int i = 0; i < n; i++) cin >> place[i] >> cost[i];
    
    solve();
    reverse(place, place + n), reverse(cost, cost + n);
    
    for(int i = 0; i < n; i++)
        place[i] = C - place[i];
    
    solve();
    
    cout << tot << '\n';
    
}
