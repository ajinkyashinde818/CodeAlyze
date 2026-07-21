#include<stdio.h>
int main(void)
{
	int n;
	int r[200000]={1000000000};
	int v=1000000001,o;
	int i;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&r[i]);
	}
	
	o=r[1]-r[0];
	
	for(i=1;i<n;i++)
	{
		
		if(v>r[i-1])
		{
			v=r[i-1];
		}
		if(o<r[i]-v)
		{
			o=r[i]-v;
		}
	}
	
	printf("%d\n",o);
	
	return 0;
}
