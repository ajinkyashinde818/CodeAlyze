//C++14 (Clang 3.8.0)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn=200003;

int main(){
  ll res=LONG_MAX;
  int n;
  cin>>n;
  ll a[maxn];
  a[0]=0LL;
  for(int i=0;i<n;i++){
    ll tmp;
    cin>>a[i+1];
    a[i+1]+=a[i];

  }
  for(int i=1;i<=n-1;i++){
    res=min(abs(a[i]-(a[n]-a[i])),res);
    
  }
  cout<<res<<endl;
  return 0;
}
