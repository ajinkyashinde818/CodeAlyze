#include<bits/stdc++.h>
using namespace std;
int r,g,b,n,ans;
int main()
{
	cin>>r>>g>>b>>n;
	for(int i=0;i*r<=n;i++)
	for(int j=0;i*r+j*g<=n;j++)
	if((n-i*r-j*g)%b==0)ans++;
	cout<<ans<<endl;
}
