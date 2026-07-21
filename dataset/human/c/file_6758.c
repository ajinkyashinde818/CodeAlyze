#include<stdio.h>
inline void read(int&x)
{
	register char c=getchar();for(;c<'0'||'9'<c;c=getchar());
	for(x=0;'0'<=c&&c<='9';x=(x<<3)+(x<<1)+(c^48),c=getchar());
}
int n,k,a[200000],l,r,m;
inline bool jg()
{
	register int ans=0;
	for(register int i=0;i<n;++i)ans+=(a[i]-1)/m+1-1;
	return ans<=k;
}
main()
{
	read(n);read(k);for(register int i=0;i<n;++i)read(a[i]);
	for(l=1,r=1<<30;l<=r;)
	{
		m=l+r>>1;
		if(jg())r=m-1;
		else l=m+1;
	}
	printf("%d",l);
}
