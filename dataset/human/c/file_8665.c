#include <stdio.h>        
int a[100005],n,x,flag=0,cnt=0;       
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	x=1;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[x]==2)
		{
			flag=1;
			cnt++;
			break;
		}
		cnt++;
		x=a[x];
	}
	if(flag==1)
		printf("%d",cnt);
	else
		printf("-1");
	return 0;
}
