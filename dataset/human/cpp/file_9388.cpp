#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,f;
  cin>>n>>m;
  string a[n],b[n];
  for(int i=0;i<n;++i){
    cin>>a[i];
  }
  for(int i=0;i<m;++i){
    cin>>b[i];
  }

  for(int i=0;i<n-m+1;++i){
    for(int j=0;j<n-m+1;++j){
      int flag = 0;
      for(int k=0;k<m;++k){
        string tmp = a[i+k].substr(j,m);
        if(tmp.compare(b[k])!=0){
          flag = 1;
          break;
        }
      }
      if(flag==0){
          cout<<"Yes"<<endl;
          return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
