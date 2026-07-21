#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int n,i,min,max,maxincome,income;
	scanf("%d",&n);
	int *p=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&p[i]);
	min=p[0];
	max=p[1];
	maxincome=p[1]-p[0];
	for(i=1;i<n;i++)
	{
		if(p[i]<min&&i+1!=n)
		{
			min=p[i];
			max=p[i+1];
			income=max-min;
			if(income>maxincome)
			maxincome=income;
		}
		else if(p[i]>min&&p[i]<max)
		continue;
		else if(p[i]>max)
		{
			max=p[i];
			income=max-min;
			if(income>maxincome)
			maxincome=income;
		}
			
	}
	printf("%d\n",maxincome);
	return 0;
}
