#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  ll sum1=a[0];
  ll sum2=0;
  for(ll i=1;i<n;i++) sum2+=a[i];
  ll m=abs(sum2-sum1);
  for(int i=1;i<n-1;i++){
    sum1+=a[i];
    sum2-=a[i];
    m=min(m,abs(sum2-sum1));
  }
  cout<<m<<endl;
}
