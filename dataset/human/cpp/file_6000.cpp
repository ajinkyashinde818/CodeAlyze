//by sdfzchy
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL inf=(1ll<<50);
inline LL in()
{
	char ch=getchar();
	LL f=1,tmp=0;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {tmp=(tmp<<1)+(tmp<<3)+(ch-'0');ch=getchar();}
	return tmp*f;
}

const int N=100010;

int n;
LL C;
LL x[N],v[N],f[N],g[N];
LL ans,ff[N],gg[N];

LL sum[N];
LL sum2[N];
LL A,B;
int main()
{
	n=in();
	C=in();
	for(int i=1;i<=n;i++) x[i]=in(),v[i]=in();
	
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+v[i];
	for(int i=n;i>=1;i--) sum2[i]=sum2[i+1]+v[i];
	
	for(int i=1;i<=n;i++) f[i]=max(f[i-1],sum[i]-x[i]);
	for(int i=n;i>=1;i--) g[i]=max(g[i+1],sum2[i]-(C-x[i]));
	for(int i=1;i<=n;i++) ff[i]=max(ff[i-1],sum[i]-2ll*x[i]);
	for(int i=n;i>=1;i--) gg[i]=max(gg[i+1],sum2[i]-2ll*(C-x[i]));
	
	for(int i=1;i<=n;i++) ans=max(ans,f[i]+gg[i+1]);
	for(int i=n;i>=1;i--) ans=max(ans,g[i]+ff[i-1]);
	cout<<ans<<endl;
	return 0;
}
