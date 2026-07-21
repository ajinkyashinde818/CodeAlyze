#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int r,g,b,n;
	cin>>r>>g>>b>>n;
	long long ans=0LL;
	for (int i = 0; i <= n; ++i)
	{
		if (i*r>n)
		{
			break;
		}
		for (int j = 0; j <= n; ++j)
		{
			if (i*r+j*g>n)
			{
				break;
			}
			if ((n-i*r-j*g)%b==0)
			{
				++ans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
