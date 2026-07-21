#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int>q(m);
  for(int i=0;i<m;i++)cin>>q[i];
  
  vector<int>used(n+1,0),ans;
  for(int i=q.size()-1;i>=0;i--)
    if(!used[q[i]]++)ans.push_back(q[i]);
  for(int i=1;i<=n;i++)if(!used[i])ans.push_back(i);
  for(int i=0;i<n;i++)cout<<ans[i]<<endl;

  return 0;
}
