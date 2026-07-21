#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long r,g,b,n,ans;
int main()
{
	long long i,j,u,v;
	cin>>r>>g>>b>>n;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			u=n-(i*r)-(j*g);
			if(u%b==0 && u/b>=0)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return(0);
}
