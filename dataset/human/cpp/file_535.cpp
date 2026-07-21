#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int r,g,b,n;
  cin>>r>>g>>b>>n;
  long long count=0;
  for(int i=0;i<=n/r;i++){
    if(i*r>n)break;
    for(int j=0;j<=n/g;j++){
      int k;
      if(i*r+j*g>n)break;
      k=(n-i*r-j*g)/b;
      if(i*r+j*g+k*b>n)break;
      if(i*r+j*g+k*b==n)count++;
    }
  }
  cout<<count<<endl;
  return 0;
}
