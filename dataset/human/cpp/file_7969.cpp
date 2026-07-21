#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
  ll sum[200000];
  ll n,a;
  cin>>n>>a;
  sum[0]=a;
  for(int i=1;i<n;i++){
    cin>>a;
    sum[i]=sum[i-1]+a;
  }
  ll ans=abs(sum[n-1]-sum[0]*2);
  for(int i=1;i<n-1;i++){
    ans=min(ans,abs(sum[n-1]-2*sum[i]));
  }

  cout<<ans<<endl;
  return 0;
}
