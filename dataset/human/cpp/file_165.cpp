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

#define bug(x) cout<<"zdongdebug: "<<x<<endl;
#define bug2(x, y) cout<<"zdongdebug: "<<x<<" "<<y<<endl;
using namespace std;
typedef long long ll;
const int maxn = 100005;



int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
#endif
  int r,g,b,n;
  scanf("%d%d%d%d",&r,&g,&b,&n);
  int ret = 0;
  for(int i=0;i*r<=n;i++)
    for(int j=0;i*r+j*g<=n;j++){
      int lt = n - i*r-j*g;
      if(lt%b==0)ret++;
    }
  cout<<ret<<endl;
  return 0;
}
