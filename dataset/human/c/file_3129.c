#include<stdio.h>
long long a[1000000],b[1000000];
int main()
{
    long long k,n,x,y,i,s;
    
    scanf("%lld%lld",&k,&n);
    s=k;
    for(i=0;i<n;i++)
    {
    scanf("%lld",&a[i]);
    }


    for(i=0;i<n;i++)
    {
    if(i==0)
    x=a[n-1]-a[i];
    else 
    x=k-(a[i]-a[i-1]);
    if(i==(n-1))
    y=a[n-1]-a[0];
    else
    y=k-(a[i+1]-a[i]);
    if(x<=y)
    b[i]=x;
    else
    b[i]=y;
  
    }
    for(i=0;i<n;i++)
    {
    if(b[i]<s)
    s=b[i];
    }
    printf("%lld",s);
}
