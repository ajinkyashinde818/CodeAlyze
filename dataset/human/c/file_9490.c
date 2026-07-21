#include<stdio.h>
int main(void)
{
	int n,d,x,a,k,c,i;
	scanf("%d %d %d", &n, &d, &x);
	for(i=0; i<n; i++)
	{
		scanf("%d", &a);
		k=1;
		c=0;
		while(k<=d)
		{
			c++;
			k+=a;
		}
		x+=c;
	}
	printf("%d\n", x);
	
	return 0;
}
