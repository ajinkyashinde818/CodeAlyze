#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,i,j,num=0,ans=0;
  cin>>n;
  vector<ll> a(n);
  for(i=0;i<n;i++){
	cin>>a[i];
  }
  sort(a.begin(),a.end());
  for(i=0;i<n;i++){
	if(a[i]>0){
      num=i;
      break;
    }
    num=n;
  }
  if(num>1){
    if(i%2==1){
  	 for(i=0;i<num-1;i++){
		 a[i]=-a[i];
     }
    }else{
      for(i=0;i<num;i++){
		 a[i]=-a[i];
      }
    }
  }	
  for(i=0;i<n;i++){
    ans+=a[i];
  }
  if(num%2==1 && num!=n){
  ans+=max(2*(-a[num]-a[num-1]),(ll)0);
  }
  cout<<ans<<endl;
}
