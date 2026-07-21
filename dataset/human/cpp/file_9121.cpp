#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  string ori[n+1];
  for(int i=0;i<n;i++){
    cin>>ori[i];
  }
  string temp[m+1];
  for(int i=0;i<m;i++)	
    cin>>temp[i];
  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      bool hoge=true;
      for(int ii=i;ii<i+m;ii++){
        for(int jj=j;jj<j+m;jj++){
          	if(ori[ii][jj]!=temp[ii-i][jj-j])hoge=false;
        }
      }
      if(hoge){cout<<"Yes"<<endl;return 0;}
    }
  }
  cout<<"No"<<endl;
  return 0;
}
