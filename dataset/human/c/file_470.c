#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
main()
{
    long long n,i,a[200005],j,sum1=0,sum2=0,sum=0,min,b=0,c=0;
   scanf("%lld",&n);
      sum1=0;sum2=0;sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            sum=sum+a[i];
        }
        for(i=0;i<n-1;i++)
        {  b=b+a[i];
          c=sum-b;
          if(i==0)
            min=fabs(b-c);
          if(fabs(b-c)<fabs(min))min=fabs(b-c);

        }
        printf("%lld\n",min);



}
