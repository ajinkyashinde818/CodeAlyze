#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,ans=1000000000000000000;
	cin>>n;
	ll a[n],s[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	s[0]=a[0];
	for(int i=1;i<n;i++)
		s[i]=a[i]+s[i-1];
	for(int i=0;i<n-1;i++)
	  ans=min(ans,abs(s[i]-(s[n-1]-s[i])));
	cout<<ans;
	return 0;
}
