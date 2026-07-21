#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  string a[n],b[m];
  for(int i=0;i<n;i++)cin>>a[i];
  for(int j=0;j<m;j++)cin>>b[j];
  for(int i=0;i<n-m+1;i++){
    for(int j=0;j<n-m+1;j++){
      int c=1;
      for(int k=i;k<i+m;k++){
        for(int l=j;l<j+m;l++){
          if(a[k][l]!=b[k-i][l-j]){
            c=0;
            break;
          }
        }
        if(c==0)break;
        
      }
      if(c==1){
        cout<<"Yes"<<endl;
        return 0;
      }
      
    }
  }
  cout<<"No"<<endl;
}
