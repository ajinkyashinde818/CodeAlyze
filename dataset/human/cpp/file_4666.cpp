#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
vector<int> v[100005];
long long cnt[2];
void dfs(int node,int pnode,int color)
{
    cnt[color]++;
    for (int i=0;i<v[node].size();i++)
    {
        if (v[node][i]!=pnode)
        dfs(v[node][i],node,!color);
    }
}
int main()
{
   int k,res;
   cin>>k>>res;
   if(k>=10) cout<<res<<endl;
   else{
       int ans=(res)+100*(10-k);
       cout<<ans<<endl;
   }
   
   return 0;
}
