#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
const Int MAX = 111;
Int dp[MAX*2][MAX];

Int dfs(Int w,Int b){
  Int &res=dp[w][b];
  if(~res) return res;
  res=0;
  set<Int> g;
  if(w) g.emplace(dfs(w-1,b));
  for(Int i=1;i<=min(w,b);i++) g.emplace(dfs(w,b-i));
  if(b) g.emplace(dfs(w+1,b-1));
  while(g.count(res)) res++;
  return res;
}

signed main(){
  Int n;
  cin>>n;
  vector<Int> w(n),b(n);
  for(Int i=0;i<n;i++) cin>>w[i]>>b[i];  
  
  memset(dp,-1,sizeof(dp));
  Int ans=0;
  for(Int i=0;i<n;i++) ans^=dfs(w[i],b[i]);

  cout<<(ans?0:1)<<endl;
  return 0;
}
