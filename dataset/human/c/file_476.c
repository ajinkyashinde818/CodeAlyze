#include<stdio.h>
#include<math.h>
long long a[200500],c[200500],d[200500],e[200500];
int main()
{
   long long n;
   while(~scanf("%lld",&n))
   {
     long long sum=0;
     for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
     for(int i=0;i<n;i++)
        sum+=a[i];  long long suml=sum;
     for(int i=0;i<n-1;i++)
       {
           sum-=a[i];
           c[i]=suml-sum;
           d[i]=suml-c[i];
       }
     for(int i=0;i<n-1;i++)
            e[i]=fabs(c[i]-d[i]);
     long long min=e[0];
     for(int i=0;i<n-1;i++)
        if(e[i]<min) min=e[i];
     printf("%lld\n",min);
   }
}
