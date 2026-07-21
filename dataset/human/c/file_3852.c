/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-13 13:49:16
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
#include<assert.h>
const int N=400010;
int n,a[N],s[N],v[N],t;
int check(int c)
{
	s[t=1]=a[1]; v[1]=1;
	fr(i,2,n) if(a[i]>a[i-1])
	{
		if(v[t]==1) s[t]=a[i];
		else{ t++; s[t]=a[i]; v[t]=1; }
	}
	else
	{
		while(s[t-1]>=a[i]) t--;
		s[t]=a[i];
		if(v[t]==c)
		{
			if(t==1) return 0;
			if(s[t-1]-1==s[t-2])
			{
				v[t-1]++; v[t]=1;
				if(v[t-1]==v[t-2])
				{
					s[t-2]=s[t-1]; v[t-1]=v[t]; s[t-1]=s[t]; t--;
				}
			}
			else
			{
				t++;
				s[t-1]=s[t-2]; s[t-2]--; s[t]=a[i];
				v[t-1]=v[t-2]+1; v[t]=1;
			}
		}
		else
		{
			if(s[t]-1==s[t-1])
			{
				v[t]++;
				if(v[t]==v[t-1]){ s[t-1]=s[t]; t--; }
			}
			else
			{
				s[t]--; t++; s[t]=s[t-1]+1; v[t]=v[t-1]+1;
			}
		}
		assert(t<=1||v[t]!=v[t-1]); assert(t<=2||v[t-1]!=v[t-2]);
	}
	return 1;
}
int main()
{
	n=read();
	fr(i,1,n) a[i]=read();
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}
