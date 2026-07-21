#include<stdio.h>
int a[262144];
int num[262144];
int inv[262144];
int pr[262144],inpr[262144],pre[262144];
int c[262144];
int n;
void inc(int wz,int val)
{
	for(int i=wz;i<=n;i+=(i&(-i)))
	{
		c[i]+=val;
		if(c[i]>=1000000007)
		{
			c[i]-=1000000007;
		}
	}
}
int query(int wz)
{
	int ans=0;
	for(int i=wz;i>0;i-=(i&(-i)))
	{
		ans+=c[i];
		if(ans>=1000000007)
		{
			ans-=1000000007;
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	int nump=1;
	num[n+1]=1;
	for(int i=n;i>0;i--)
	{
		num[i]+=num[i+1]-1;
		if(num[i]==0)
		{
			printf("0\n");
			return 0;
		}
		nump=(long long)nump*num[i]%1000000007;
	}
	inv[1]=1;
	for(int i=2;i<=n;i++)
	{
		inv[i]=(long long)1000000007/i*inv[1000000007%i]%1000000007;
		inv[i]=1000000007-inv[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i]==1)
		{
			pre[i]=i;
			pr[i]=1;
			inpr[i]=1;
		}
		else
		{
			pre[i]=pre[i-1];
			pr[i]=(long long)pr[i-1]*(num[i]-1)%1000000007;
			pr[i]=(long long)pr[i]*inv[num[i]]%1000000007;
			inpr[i]=(long long)inpr[i-1]*inv[num[i]-1]%1000000007;
			inpr[i]=(long long)inpr[i]*num[i]%1000000007;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		c[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int val=query(a[i])-query(pre[a[i]]-1);
		if(val<0)
		{
			val+=1000000007;
		}
		ans+=(long long)val*pr[a[i]]%1000000007;
		if(ans>=1000000007)
		{
			ans-=1000000007;
		}
		inc(a[i],inpr[a[i]]);
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=0;
	}
	for(int i=n;i>=1;i--)
	{
		int val=query(a[i]-1)-query(pre[a[i]]-1);
		if(val<0)
		{
			val+=1000000007;
		}
		ans-=(long long)val*pr[a[i]]%1000000007;
		if(ans<0)
		{
			ans+=1000000007;
		}
		inc(a[i],inpr[a[i]]);
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=0;
	}
	for(int i=n;i>=1;i--)
	{
		ans+=query(a[i]-1);
		if(ans>=1000000007)
		{
			ans-=1000000007;
		}
		inc(a[i],2);
	}
	ans=(long long)ans*500000004%1000000007;
	ans=(long long)ans*nump%1000000007;
	printf("%d\n",ans);
	return 0;
}
