#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline ll ri()
{
	register ll x=0;register bool f=0;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();};
	return f?-x:x;
}
void wi(ll x)
{
	if(x<0)	x=-x,putchar('-');
	if(x>9)	wi(x/10);
	putchar('0'+x%10);
}
const int N=1e5+7;
ll x[N],cx[N],v[N],f0[N],f1[N],cf0[N],cf1[N],mf0[N],mf1[N],mcf0[N],mcf1[N];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ll n=ri(),c=ri(),i,ans=0;
	for(i=1;i<=n;i++)	x[i]=ri(),v[i]=ri(),cx[i]=c-x[i];
	for(i=1;i<=n;i++)
	{
		f1[i]=f1[i-1]+v[i]-(x[i]-x[i-1]);
		f0[i]=f0[i-1]+v[i]-2*(x[i]-x[i-1]);
		mf0[i]=max(mf0[i-1],f0[i]);
		mf1[i]=max(mf1[i-1],f1[i]);
		ans=max(ans,f1[i]);
	}
	for(i=n;i>=1;i--)
	{
		cf1[i]=cf1[i+1]+v[i]-(cx[i]-cx[i+1]);
		cf0[i]=cf0[i+1]+v[i]-2*(cx[i]-cx[i+1]);
		mcf0[i]=max(mcf0[i+1],cf0[i]);
		mcf1[i]=max(mcf1[i+1],cf1[i]);
		ans=max(ans,cf1[i]);
	}
	for(i=1;i<n;i++)
	{
		ans=max(ans,mf0[i]+mcf1[i+1]);
		ans=max(ans,mf1[i]+mcf0[i+1]);
	}
	wi(ans);putchar('\n');
	return 0;
}
/*
3 20
2 80
9 120
16 1

191

3 20
2 80
9 1
16 120

15 10000000000
400000000 1000000000
800000000 1000000000
1900000000 1000000000
2400000000 1000000000
2900000000 1000000000
3300000000 1000000000
3700000000 1000000000
3800000000 1000000000
4000000000 1000000000
4100000000 1000000000
5200000000 1000000000
6600000000 1000000000
8000000000 1000000000
9300000000 1000000000
9700000000 1000000000

*/
