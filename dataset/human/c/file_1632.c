/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-10 16:51:59
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const int N=10000010,mod=998244353;
i64 f[N],F[N],ans;
int n,a,b;
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 C(i64 a,i64 b){ return b>=0&&a>=b?f[a]*F[b]%mod*F[a-b]%mod:0; }
int main()
{
	n=read(); a=read(); b=read(); f[0]=1; a=b-a;
	fr(i,1,n) f[i]=f[i-1]*i%mod;
	F[n]=power(f[n],mod-2,mod);
	fd(i,n,1) F[i-1]=F[i]*i%mod;
	if(!b){ printf("1\n"); return 0; }
	if(b>n){ printf("0\n"); return 0; }
	fr(i,0,b-1) if(i+b<=n)
	{
		if(i+b==n&&b-i==a) ans=(ans+C(b+i-1,b-1)-C(b+i-1,b)+mod)%mod;
		else ans=(ans+(C(b+i-1,b-1)-C(b+i-1,b)+mod)*C(n-b-i-1+(b-a-i+1)-1,n-b-i-1))%mod;
//		printf("%d %d %d %d  %d %d\n",i,int(ans),int(C(b+i-1,b-1)),int(C(b+i-1,b)),n-b-i-1,b-a-i+1);
	}
	// put n-b-i-1 in b-i-a+1
	printf("%d\n",int(ans));
	return 0;
}
