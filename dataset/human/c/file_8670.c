#include <stdio.h> 
int a[100000],n;       
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int x=1,y=0;
	for(int i=1;i<=n;i++)
	{
		x=a[x];
		y++;
		if(x==2)
			break;
	}
	if(x==2)
		printf("%d\n",y);
	else
		printf("-1\n");
	return 0;
}
