#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,a[100000];
bool f=false;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
		f^=1;
	}
	if(f)
	{
		int mn=1000000000,mi=0;
		for(int i=0;i<n;i++)
		{
			if(abs(a[i])<mn)
			{
				mn=abs(a[i]);
				mi=i;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(i!=mi)
			ans+=abs(a[i]);
			else
			ans+=abs(a[i])*-1;
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		ans+=abs(a[i]);
	}
	cout<<ans;
	return 0;
}
