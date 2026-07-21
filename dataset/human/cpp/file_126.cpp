#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <numeric>
#include <random>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int r,g,b,n;
  ll ans=0ll;
  cin>>r>>g>>b>>n;
  for(int i=0;i<=3000;i++){
    for(int j=0;j<=3000;j++){
      if(n-r*i-g*j>=0 && (n-r*i-g*j)%b==0)ans++;
    }
  }
  cout<<ans<<endl;

}
