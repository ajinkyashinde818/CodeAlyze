#include<stdio.h>
int a[262144];
int wz[262144],val[262144];
int num=0;
int mid;
bool inc(int wz1)
{
	if(wz1<=0)
	{
		return false;
	}
	if(mid==1)
	{
		return false;
	}
	while(num)
	{
		if(wz[num-1]<=wz1)
		{
			break;
		}
		num--;
	}
	if(!num)
	{
		wz[num]=wz1;
		val[num]=0;
		num++;
	}
	if(wz[num-1]<wz1)
	{
		wz[num]=wz1;
		val[num]=0;
		num++;
	}
	val[num-1]++;
	if(val[num-1]==mid)
	{
		return inc(wz1-1);
	}
	return true;
}
int len=0;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int l=1,r=n;
	while(l<r)
	{
		mid=((l+r)>>1);
		num=0;
		len=0;
		bool ok=true;
		for(int i=0;i<n;i++)
		{
			if(a[i]>len)
			{
				len=a[i];
			}
			else
			{
				len=a[i];
				if(!inc(len))
				{
					ok=false;
					break;
				}
			}
		}
		if(ok)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%d\n",l);
	return 0;
}
