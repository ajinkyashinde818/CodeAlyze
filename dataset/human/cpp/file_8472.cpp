/**
     **author : _KMS_
     **created : 07-03-2020
**/
#include<bits/stdc++.h>
using namespace std;
const long long M =1e6,MOD=2e9;
typedef long long ll;
char ch[100][100],ch2[100][100];
int main() {
      
   ios::sync_with_stdio(false);
   cin.tie(0);
  int m,n;
  cin>>n>>m;
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)cin>>ch[i][j];
  for(int i=0;i<m;i++)
  for(int j=0;j<m;j++)cin>>ch2[i][j];
  for(int i=0;i<=n-m;i++)
  {
        for(int j=0;j<=n-m;j++)
        {
              int c=0;
              bool f=1;
             for(int k=i;k<i+m;k++)
             {
                   int b=0;
                   for(int t=j;t<j+m;t++)
                   {
                         if(ch[k][t]!=ch2[c][b])
                         {
                               f=0;
                               break;
                         }
                         b++;
                   }
                   if(!f)break;
                   c++;
             }
             if(f)
             {
                   cout<<"Yes\n";
                   return 0;
             }
        }
  }
  cout<<"No\n";
   return 0;
}
