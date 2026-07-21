#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
using ll = long long int;
using graph = vector<vector<int>>;
using wgraph = vector<vector<pair<int, lint>>>;
const lint INF = 1001001001001001LL;
const lint MOD = 1000000007LL;
const double PI = 3.1415926535897932;
int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

void yes(){ cout << "yes" << endl; }
void Yes(){ cout << "Yes" << endl; }
void YES(){ cout << "YES" << endl; }
void no(){ cout << "no" << endl; }
void No(){ cout << "No" << endl; }
void NO(){ cout << "NO" << endl; }
void possible(){ cout << "possible" << endl; }
void Possible(){ cout << "Possible" << endl; }
void POSSIBLE(){ cout << "POSSIBLE" << endl; }
void impossible(){ cout << "impossible" << endl; }
void Impossible(){ cout << "Impossible" << endl; }
void IMPOSSIBLE(){ cout << "IMPOSSIBLE" << endl; }

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for(int i = s; i < t; i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()


int main(){
  
  lint n; cin >> n;
  vector<lint> a(n);
  lint cntNeg = 0;
  rep(i, n){
    cin >> a[i];
    if(a[i] < 0) cntNeg++;
    a[i] = (lint)abs(a[i]);
  }

  cntNeg %= 2;
  lint ans = 0;
  sort(rall(a));
  rep(i, n - cntNeg){
    ans += (lint)abs(a[i]);
  }
  if(cntNeg == 1) ans -= a[n - 1];
  cout << ans << endl;
  return 0;
}
