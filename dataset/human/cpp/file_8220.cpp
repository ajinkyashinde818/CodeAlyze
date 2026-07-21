#include <bits/stdc++.h>
using namespace std;

int main(){
  long long ans,n,array[200000],snuke,kuma=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>array[i];
    if(i){
      kuma+=array[i];
    }
  }
  snuke=array[0];
  ans=abs(snuke-kuma);
  for(int i=1;i<n-1;i++){
    snuke+=array[i];
    kuma-=array[i];
    ans=min(ans,abs(snuke-kuma));
  }
  cout<<ans<<endl;
}
