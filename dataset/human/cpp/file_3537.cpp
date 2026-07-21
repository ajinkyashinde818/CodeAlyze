#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,cnt=0,sum=0;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
	{
	    cin>>a[i];
	    if(a[i]<=0)
	        cnt++;
	        
	   a[i]=abs(a[i]);
	}
	sort(a,a+n);
	if(cnt%2==0)
	{
	    sum+=a[0];
	}
	else
	{
	    sum-=a[0];
	}
	for(ll i=1;i<n;i++)
	{
	    sum+=a[i];
	}
	cout<<sum<<endl;
	return 0;
}
