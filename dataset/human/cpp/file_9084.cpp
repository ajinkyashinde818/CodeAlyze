#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  bool ans = 0;
  char a[55][55],b[55][55];
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      cin>>a[i][j];
  for(int i=0;i<m;++i)
    for(int j=0;j<m;++j)
      cin>>b[i][j];
  [&](){
	  for(int i=0;i<=n-m;++i){
        for(int j=0;j<=n-m;++j){
          bool fl=1;
          for(int k=i;k<i+m;++k){
            for(int l=j;l<j+m;++l){
              if(a[k][l]!=b[k-i][l-j]){
                fl=0;
                break;
              }
              if(!fl)break;
            }
            if(!fl)break;
            if(k==i+m-1){
              ans=1;
              return;
            }
          }
        }
      }
  }();
      cout<<(ans?"Yes":"No")<<endl;
  }
