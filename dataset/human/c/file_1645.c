#include<stdio.h>
int main()
{
int n;
int i;
int m;
int sum;
int a[21],b[21],c[21];
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

for(i=0;i<n;i++)
{
scanf("%d",&b[i]);

}

for(i=0;i<n-1;i++)
{
scanf("%d",&c[i]);

}
m=0;sum=0;
for(i=0;i<n;i++)
{
 m=a[i];
 sum+=b[m-1];
 //printf("%d ",b[m]);
}

//printf("%d\n",sum);

for(i=0;i<n;i++)
{
	m=a[i];
	if(m==a[i+1]-1)
	{
	sum+=c[m-1];
	}

}
printf("%d\n",sum);
/**/
return 0;
}
