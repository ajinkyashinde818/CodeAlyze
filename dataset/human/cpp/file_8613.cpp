#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,i,j,i2,j2;
  cin>>n>>m;
  string a[n],b[m];
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  for(i=0;i<m;i++){
    cin>>b[i];
  }
  int cnt;
  for(i=0;i<n-m+1;i++){
  	for(j=0;j<n-m+1;j++){
      cnt=0;
      for(i2=0;i2<m;i2++){
      	for(j2=0;j2<m;j2++){
          if(a[i2+i][j2+j]!=b[i2][j2]){
            cnt++;
            break;
          }
        }
        if(cnt!=0)break;
      }
      if(cnt==0){
        cout<<"Yes";
        return 0;
      }
    }
  }
  cout<<"No";
}
