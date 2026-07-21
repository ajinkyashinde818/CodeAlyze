#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,ans=0;
int main()
{
	cin>>a>>b>>c>>n;
	for(int i=0;i<=n;i+=a) for(int j=0;i+j<=n;j+=b) if((n-i-j)%c==0) ans++;
	cout<<ans<<endl;
}
