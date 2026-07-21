#include<bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b,n; cin>>r>>g>>b>>n;
  int count=0;
  for(int i=0;i<=n/r;i++){
    for(int j=0;j<=n/g;j++){
      if((n-i*r-j*g)%b==0){
        int k=(n-i*r-j*g)/b;
        if(i==0 && j==0 && k==0)
          continue;
        else if(k<0)
          continue;
        else
          count++;
      }
    }
  }
  cout<<count<<endl;
}
