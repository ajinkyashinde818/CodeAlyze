#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pint;
typedef pair<double,int> pdi;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)


int main(void) {
  ll R,G,B,N;
  ll ans = 0;
  cin >> R >> G >> B >> N;

  ll tmp,zan;
  REP(r,N/R+3){
    REP(g,N/G+3){
      tmp = r*R + g*G;
      zan = N - tmp;
      if(0 <= zan && zan%B == 0){
        ans ++;
      }
    }
  }

  cout << ans << endl;
}
