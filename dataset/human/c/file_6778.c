#include<stdio.h>
#define MAXN 220000
int a[MAXN],n,k;

int read()
{
	int ans=0,p=1;
	char c = getchar();
	while (c<'0'||c>'9')
	{
		if(c=='-')
			p=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ans = ans*10+c-'0';
		c=getchar();
	}
	return ans*p;
//	int a;
//	scanf("%d",&a);
//	return a;
}

int solve(int m)
{
	int ans=0;
	for(int i = 1; i <= n; i++)
	{
		ans += a[i]/m;
		if(a[i]%m==0)
			ans--;
		if(ans>k)
			return 0;
	}
	return 1;
}

int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}	
	int A = 1, B = 2e9;
	while(A < B)
	{
		int mid = (A+B)>>1;
		if(solve(mid) != 1)
		{
			A = mid+1;
		}
		else 
		{
			B = mid;
		}
	}
	printf("%d",B);
	return 0;
}
