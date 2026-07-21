#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,count=0;
  long long int a,ans=0,mins=LLONG_MAX;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a<0){
      count++;
      a*=-1;
    }
    mins=min(mins,a);
    ans+=a;
  }
  if(count%2==0) cout<<ans<<endl;
  else cout<<ans-(mins*2)<<endl;
  return(0);
}
