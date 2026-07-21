#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <string>
#include <random>
#include <stack>
#include <set>
#include <unordered_set>

using namespace std;
typedef long long ll;
const int maxn = 100005;
const ll mm = (1LL<<60);
int n;
ll a[maxn];
ll f[maxn][2];

int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
#endif
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  f[0][0]=a[0];
  f[0][1]=-mm;
  for(int i=1;i<n;i++)
    for(int j=0;j<2;j++){
      f[i][j]=-mm;
      for(int k=0;k<2;k++){
        ll add = 0;
        if(k){
          // -a[i-1] -> a[i-1]-a[i]
          if(j)add=2*a[i-1]-a[i];
          else add=a[i];
        } else {
          if(j)add=-2*a[i-1]-a[i];
          else add=a[i];
        }
        f[i][j]=max(f[i][j], f[i-1][k]+add);
      }
    }
  //cout<<f[2][1]<<endl;
  cout<<max(f[n-1][0],f[n-1][1])<<endl;
  return 0;
}
