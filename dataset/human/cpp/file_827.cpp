#include<bits/stdc++.h>
using namespace std;
int a[3],b[3];
int n;
int main()
{
	cin>>a[0]>>a[1]>>a[2]>>n;
	sort(a,a+3);
	int ans=0;
	int df=-1,di=-1;
	if(a[0]==a[1])
	{
		df=2;di=1;
	}
	else
	{
		if(a[0]==a[2])
		{
			df=1;di=2;
		}
		else
		if(a[1]==a[2])
		df=0,di=1;
	}
	if(df==-1)
	{
		for(int i=n/a[0];i>=0;i--)
			for(int j=(n-i*a[0])/a[1];j>=0;j--)
				for(int k=(n-i*a[0]-j*a[1])/a[2];k>=0;k--)
				{
					if(i*a[0]+j*a[1]+k*a[2]==n)
					ans++;
				}	
	}
	
	else
	{
		for(int i=n/a[df];i>=0;i--)
		{
			if((n-i*a[df])%a[di]!=0)
			continue;
			ans+=(n-i*a[df])/a[di]+1;
		}
	}
	cout<<ans;
	return 0;
}
