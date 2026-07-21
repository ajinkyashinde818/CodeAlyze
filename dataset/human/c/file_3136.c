#include <stdio.h>
#include <stdlib.h>
long long a[200005]={0};
long long b[200005]={0};
int main() 
{
    long long x,i,j,k,sum=0,max=0;
    scanf("%lld%lld",&x,&k);
    for(i=0;i<k;i++)
    {
    	scanf("%lld",&a[i]);
	}
     for(i=0;i<k-1;i++)
	 {
	 	b[i]=a[i+1]-a[i];
   	} 
   	b[k-1]=x-(a[k-1]-a[0]);
	 for(i=0;i<k;i++)
	  {
		if(max<b[i])
		   max=b[i];
	 } 
	 for(i=0;i<k;i++)
	 {
	 	sum=sum+b[i];
	 }
    
	sum=sum-max;
	printf("%lld",sum); 
    return 0;
}
