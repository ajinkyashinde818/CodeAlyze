#include<bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b,n,sum,ans=0;
  cin>>r>>g>>b>>n;
  for(int i=0;i<=n/r;i++){
    for(int j=0;j<=n/g;j++){
        sum=r*i+g*j;
        if(sum>n)break;
        if((n-sum)%b==0){
          ans++;
        }
      }
  }
  cout<<ans<<endl;
  return 0;
}
