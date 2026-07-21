#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin>>n;
  vector<ll> arr(n);
  for(ll i=0;i<n;i++)
    cin>>arr[i];
  ll neg=0;
  for(ll i=0;i<n;i++)
  	if(arr[i]<0)
    	{neg++;arr[i] = -arr[i];}
  
  sort(arr.begin(),arr.end());
  ll sum =0;
  for(ll i=1;i<n;i++)
    sum+=arr[i];
  if(neg%2==0)
  sum += arr[0];
  else sum -= arr[0];
  cout<<sum<<endl;
}
