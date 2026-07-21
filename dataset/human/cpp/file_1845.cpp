#include<iostream>
using namespace std;
 
int main(){
 
  int n, m, e, a[100000];
  bool f[200001]={};
 
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>e;
    a[i]=e;
  }
 
  for(int i=m-1;i>=0;i--){
    if(f[a[i]]==false){
      cout<<a[i]<<endl;
      f[a[i]]=true;
    }
  }
  for(int i=1;i<=n;i++){
    if(f[i]==false) cout<<i<<endl;
  }
 
  return 0;
}
