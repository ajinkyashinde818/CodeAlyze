#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
typedef long long ll;
using namespace std;

int main(void){
    int b[3],N,i,j,k;
  for(i=0;i<3;i++)cin>>b[i];
  cin>>N;
  sort(b,b+3);
  
  int ans=0;
  int n,m[3];
  for(i=0;i<3;i++)m[i]=N/b[i]+1;
  for(i=0;i<m[2];i++){
    n=N-i*b[2];
    if(n<0)break;
    for(j=0;j<m[1];j++){
      if(n%b[0]==0)ans++;
      n-=b[1];
      if(n<0)break;
    }
  }

  cout<<ans<<endl;
  
  return 0;
}
