#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010


int main(){
  int n, v[SIZE], rv[SIZE];
  ll sumv[SIZE], sumrv[SIZE];
  ll c, x[SIZE], rx[SIZE];
  ll maxS[SIZE], maxrS[SIZE];

  scanf("%d%lld",&n, &c);

  for(int i=0;i<n;i++){
    scanf("%lld%d",x+i, v+i);
    rv[n-1-i] = v[i];
    rx[n-1-i] = c - x[i];
  }

  ll ans = 0;

  sumv[0] = v[0];
  sumrv[0] = rv[0];
  maxS[0] = v[0] - x[0]*2;
  maxrS[0] = rv[0] - rx[0]*2;
  ans = max(ans, sumv[0] - x[0]);
  ans = max(ans, sumrv[0] - rx[0]);   

  for(int i=1;i<n;i++){
    sumv[i]  = sumv[i-1] + v[i];
    sumrv[i] = sumrv[i-1] + rv[i];
    maxS[i]  = max(sumv[i]  - x[i]*2, maxS[i-1]);
    maxrS[i] = max(sumrv[i] - rx[i]*2, maxrS[i-1]);
    ans = max(ans, sumv[i]  - x[i]);
    ans = max(ans, sumrv[i] - rx[i]);
  }
  
  for(int i=0;i<n-1;i++){
    ans = max(ans, sumv[i]  - x[i] + maxrS[n-i-2]);
    ans = max(ans, sumrv[i] - rx[i] + maxS[n-i-2]);
  }

  cout << ans << endl;
    
  return 0;
}
