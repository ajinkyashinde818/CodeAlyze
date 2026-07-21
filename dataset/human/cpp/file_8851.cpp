#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> a,b;
bool gazou(int i,int j){
  int k,l;
  for(k=0;k<b.size();k++){
    for(l=0;l<b.size();l++){
      if(a[i+k][j+l]!=b[k][l]) return false;
    }
  }
  return true;
}

int main(void){
  int m,n;
  cin>>n>>m;
  a.resize(n);
  b.resize(m);
  int i,j;

  for(i=0;i<n;i++) cin>>a[i];
  for(i=0;i<m;i++) cin>>b[i];
  int flag=0;
  int k,l;
  for(i=0;i<=n-m;i++){
    for(j=0;j<=n-m;j++){
      if(gazou(i,j)) {cout<<"Yes"<<endl;return 0;}
    }
  }
  cout<<"No"<<endl;
  return 0;
}
