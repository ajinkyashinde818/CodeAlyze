#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <random>
#include <stack>
#include <set>
#include <unordered_set>

#define bug(x) cout<<"zdongdebug1: "<<x<<endl;
#define bug2(x, y) cout<<"zdongdebug2: "<<x<<" "<<y<<endl;
#define bug3(x, y, z) cout<<"zdongdebug3: "<<x<<" "<<y<<" "<<z<<endl;
using namespace std;
typedef long long ll;
const int maxn = 200005;
const int mod = 1000000007;

int a[maxn],b[maxn];

int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
  //freopen("/Users/suiyuan2009/CLionProjects/icpc/output.txt", "w", stdout);
#endif
  int n;
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  sort(b,b+n, greater<int>());
  int l = -1, r = -1;
  for(int i=0;i<n;i++){
    if(a[i]==b[i]){
      r = i;
      if(l==-1)l = i;
    }
  }
  if(l!=-1){
    int cur = l;
    for(int i=0;i<n;i++){
      if(i>=l&&i<=r)continue;
      if(cur>r)break;
      if(a[i]!=a[l]&&b[i]!=a[l]){
        swap(b[i], b[cur]);
        cur++;
      }
    }
    if(cur<=r){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  for(int i=0;i<n;i++){
    cout<<b[i]<<(i==n-1?'\n':' ');
  }
  return 0;
}
