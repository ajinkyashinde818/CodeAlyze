#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
inline void rd(int &x)
{
	x=0;register char k=getchar();int s=1;
	while(k>'9'|k<'0'){if(k=='-')s=-1;k=getchar();}
	while(k>='0'&&k<='9')x=x*10+k-48,k=getchar();x*=s;
}
int main()
{
	int r,g,b,n,ans=0;
	cin>>r>>g>>b>>n;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			int now=n-i*r-j*g;
			if(now%b||now<0)continue;ans++;//cout<<i<<" "<<j<<" "<<now/b<<endl;
		}
	}cout<<ans;
}
