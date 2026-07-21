#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<string> a(n),b(m);bool flag;
  for(auto &i:a) cin>>i;
  for(auto &i:b) cin>>i;

  for(int i=0;i+m<=n;i++)
    for(int j=0;j+m<=n;j++)
      {
        flag=true;
        for(int k=0;k<m;k++)
          if(a[i+k].substr(j,m)==b[k])
            continue;
          else
            {flag=false;break;}
        if(flag)
          {
            cout<<"Yes\n";return 0;
          }
      }

  cout<<"No\n";
  return 0;
}
