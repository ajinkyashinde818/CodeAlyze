#include <stdio.h>
int main(void)
{
	int n,a[100001],c[100001]={0},x=0,i;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	scanf("%d", &a[i]);
	i=1;
	while(i!=2&&c[i]==0)
	{
		x++;
		c[i]++;
		i=a[i];
	}
	if(c[i]>0)
	printf("-1\n");
	else
	printf("%d\n", x);
	
	return 0;
}
