#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,x,y;
string a[50],b[50];
bool res=false;
int main()
{
  cin>>n>>m;
  for(;i<n;i++)cin>>a[i];
  for(i=0;i<m;i++)cin>>b[i];

  for(i=0;i<n-m+1;i++){
    for(;j<n-m+1;j++){
      for(;x<m;x++){
        if(b[0].compare(a[i].substr(j,m))!=0)break;
        if(x==m-1)res=true;
      }
    }
    if(res)break;
  }
  cout<<(res?"Yes":"No")<<endl;
}
