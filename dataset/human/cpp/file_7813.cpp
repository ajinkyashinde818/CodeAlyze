#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <climits>
#include <bitset>

using namespace std;
typedef long long ll;

//最小公倍数
ll gcd(ll x, ll y) {
  ll tmp = 0;
  if (x < y){
    tmp=x;
    x=y;
    y=tmp;
  }
  while (y > 0) {
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

//最大公倍数
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}


//for(int i = ; i < ; i++){}

int main(){
  int n;
  cin>>n;
  int a[n];
  int b[n];
  ll sum = 0;
  for(int i = 0; i < n; i++){
    cin>>a[i];
    sum+=a[i];
  }
  sum-=a[0];
  ll sum2 = a[0];
  ll ans = abs(sum-a[0]);
  for(int i = 1; i < n-1; i++){
    sum-=a[i];
    sum2+=a[i];
    ans = min(ans,abs(sum-sum2));
  }
  cout<<ans<<endl;
  return 0;
}
