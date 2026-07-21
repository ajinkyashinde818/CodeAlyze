#include<iostream>
using namespace::std;

int main(){
  int n,m;
  cin>>n>>m;
  char a[n][n+1],b[m][m+1];
  for(int i=0;i<n;i++)
      cin>>a[i];
  for(int i=0;i<m;i++)
      cin>>b[i];
  
  bool can=0;
  for(int i=0;i<n-m+1 &&!can;i++)
    for(int j=0;j<n-m+1&&!can;j++){
      bool still=1;
      for(int k=0;k<m&&still;k++)
        for(int l=0;l<m&& still;l++)
          if(a[i+k][j+l]!=b[k][l]) still=0;
      can=still;
    }
  cout<<(can?"Yes\n":"No\n");
}
