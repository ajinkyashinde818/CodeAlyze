#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  int minus=0;
  for(i=0;i<n;i++){
    if(a[i]<0)minus++;
  }
  for(i=0;i<n;i++)a[i]=max(a[i],-a[i]);
  sort(a,a+n);
  ll sum=0;
  for(i=0;i<n;i++)sum+=a[i];
  if(minus%2==1){
    sum-=2*a[0];
  }
  cout<<sum;
}
