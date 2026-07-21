#include<stdio.h>
int main()
{
 int n;
 scanf("%d",&n);
 int a[n],b[n],c[n-1];

 for(int i=0;i<n;i++)
 scanf("%d",&a[i]);

 for(int i=0;i<n;i++)
 scanf("%d",&b[i]);

 for(int i=0;i<n-1;i++)
 scanf("%d",&c[i]);

 int count=0;

for(int i=0;i<n;i++)
{
    count+=b[a[i]-1];


}
for(int i=1;i<n;i++)
{
    if(a[i]-1==a[i-1])
        count+=c[a[i-1]-1];
}
printf("%d",count);
}
