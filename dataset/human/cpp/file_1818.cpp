#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define fi first
#define se second

#define INF 2147483600

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> vec(m);
  rep(i,m) scanf("%d", &vec[i]);

  vector<bool> used(n+1, false);
  for(int i=m-1; i>=0; i--){
    if(!used[vec[i]]) printf("%d\n", vec[i]);
    used[vec[i]]=true;
  }
  for(int i=1; i<=n; i++) if(!used[i]){
    printf("%d\n", i);
  }

  return 0;
}
