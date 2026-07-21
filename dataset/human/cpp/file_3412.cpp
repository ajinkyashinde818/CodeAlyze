#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ji,a[N],mi=1e9;
long long ans=0;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mi=min(mi,abs(a[i]));
		if(a[i]<0)ji++;
	}
	if(ji%2==0)
		for(int i=0;i<n;i++)
			ans+=abs(a[i]);
	else{
		bool f=true;
		for(int i=0;i<n;i++)
		{
			if(abs(a[i])==mi&&f)
			{
				f=false;
				ans-=abs(a[i]);
			}
			else
				ans+=abs(a[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
