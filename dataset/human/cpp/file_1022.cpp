#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r,g,b,n;
	cin>>r>>g>>b>>n;
	int ans=0;
	for (int i=0;i<=n;i++) 
		for (int j=0;j<=n;j++) {
			int t=r*i+g*j;
			if (n-t<0 || (n-t)%b) continue;
			ans++;
		}
	cout<<ans<<endl;	
	return 0;
}
