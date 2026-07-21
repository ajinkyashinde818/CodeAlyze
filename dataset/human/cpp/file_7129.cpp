#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,a[500005],b[500005],i,k;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	b[0]=a[0];
	for(i=1;i<n;i++)b[i]=b[i-1]+a[i];

	ll mn=10000000000;
 	for(i=1;i<n;i++)
 	{
 		
 		ll p=abs(b[n-1]-b[i-1]-b[i-1]);
 		//cout<<p<<" "<<b[i-1]<<endl;
 		mn=min(p,mn);
 	    //cout<<mn<<endl;
 	}
 	cout<<mn<<endl;
}
