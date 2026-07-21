#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin>>n;
  long long a[n];
  bool zero=0;
  int nega=0;
  long long ans=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==0) zero=1;
    else if(a[i]<0) nega++;
    a[i]=abs(a[i]);
    ans+=a[i];
  }
  
  sort(a,a+n);
  if(zero) cout<<ans<<endl;
  else{
    if(nega%2==0) cout<<ans<<endl;
    else cout<<ans-2*a[0]<<endl;
  }
  
}
