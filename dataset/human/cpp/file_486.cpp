#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,g,b,n,i,j,k,left,tr,tg,tb;
	long long ans=0;
	cin>>r>>g>>b>>n;
	for(i=n/r;i>=0;i--)
	{
		left=n-r*i;
		if(left==0)
		{
			ans++;
			continue;
		}
		for(j=left/g;j>=0;j--)
		{
			left=n-r*i-g*j;
			if(left%b==0)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
