#include<bits/stdc++.h>
using namespace std;

int n,m;

int main(){
  cin>>n>>m;

  for(int i=0;i<n;i++){
    if(i)cout<<' ';
    if(i<n/2-1+n%2)cout<<0;
    else cout<<m;
  }
  
  cout<<endl;
  return 0;
}
