#include<stdio.h>

int main()
{
int n,i,R[200000],maxv,minv,a;

scanf("%d",&n);

for(i=0;i<n;i++)
{
scanf("%d",&R[i]);
}

maxv=R[1]-R[0];
minv=R[0];

for(i=1;i<=n-1;i++)
{
a=R[i]-minv;
if(maxv<a) maxv=a;
if(minv>R[i]) minv=R[i];
}
printf("%d\n",maxv);
return 0;
}
