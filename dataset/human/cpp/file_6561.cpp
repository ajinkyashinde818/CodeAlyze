#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  std::string s;
  std::cin>>n>>s;

  ll ans=1,query=0;

  rep(i,0,2*n){
    if(s[i]=='B'){
        if(query%2==1){
          ans=(ans*query)%MOD;
          query--;
        }else{
          query++;
        }
    }else{
      if (query % 2 == 0) {
        ans = (ans * query) % MOD;
        query--;
      } else {
        query++;
      }
    }

    if(2*n-1-i<query)ans=0;
  }

  ll temp=1;

  rep(i,1,n+1)temp=(temp*i)%MOD;

  std::cout<<(temp*ans)%MOD;


  return 0;
}
