#include<bits/stdc++.h>
using namespace std;

int main(){
int a,b,c,n,f;
cin>>a>>b>>c>>n;
  f=0;
for(int i=0;i<n/a+1;i++){
  for(int j=0;j<(n-i*a)/b+1;j++){
    if((n-i*a-b*j)%c==0){
      f++;
    }
  }
}
  cout<<f<<endl;
}
