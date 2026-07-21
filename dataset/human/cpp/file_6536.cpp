#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		fh=-1,jp=getchar();
	while (jp>='0'&&jp<='9')
		out=out*10+jp-'0',jp=getchar();
	return out*fh;
}
const int P=1e9+7;
int add(int a,int b)
{
	return (a+b>=P)?(a+b-P):(a+b);
}
int mul(int a,int b)
{
	return 1LL * a * b % P;
}
const int MAXN=2e5+10;
int a[MAXN],n;
char buf[MAXN];
int solve()
{
	int ans=1,t=0;
	for(int i=1;i<=2*n;++i)
	{
		if(a[i])
			++t;
		else
		{
			if(t==0)
				return 0;
			ans=mul(ans,t);
			--t;
		}
	}
	if(t>0)
		return 0;
	for(int i=1;i<=n;++i)
		ans=mul(ans,i);
	return ans;
}
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("c.out","w",stdout);
	n=read();
	scanf("%s",buf+1);
	for(int i=1;i<=2*n;++i)
		a[i]=!(buf[i]=='B')^(i&1);
	cout<<solve()<<endl;
	return 0;
}
