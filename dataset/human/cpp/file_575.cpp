#include<bits/stdc++.h>
using namespace std;
int n,r,g,b,ans;
int main()
{
	cin>>r>>g>>b>>n;
	for(int i=0;i<=3000;i++)
	{
		for(int j=0;j<=3000;j++)
		{
			int now=i*r+j*g;
			if(now>n)
			{
				break;
			}
			if((n-now)%b==0)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
