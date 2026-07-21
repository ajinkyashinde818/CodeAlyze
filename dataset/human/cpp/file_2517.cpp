#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>

#define dump(x) cerr << #x << "=" << (x) << endl;
using namespace std;
using ll = long long;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define IN(x) int (x); cin >> x
#define VINT(a,n) vector<int> a(n)
#define VIN(a,n) VINT(a,n); REP(i,n){cin >> a[i];}
#define ALL(x) (x).begin(),(x).end()

int main () {
  IN(n);
  VIN(a,n);
  int count=0;
  sort(ALL(a));

  REP(i,n){
    if (a[i]<0) {
      count++;
      a[i]*=-1;
    }
    else break;
  }
  ll ans;
  if (count%2 == 0){
    ans=accumulate(ALL(a),(ll)0);
  }
  else{
    sort(ALL(a));
    ans=-a[0]+accumulate(a.begin()+1, a.end(), (ll)0);
  }
  cout<<ans<<endl;
  
  
}
