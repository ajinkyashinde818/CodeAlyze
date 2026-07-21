#include<stdio.h>

int main()
{
    long long int n ;
    scanf("%lld",&n);
    if(n & 1)printf("0\n");
   
    else
    {   long long int sum=0;
         n/=2;
        while(n>0)
        {
            sum+=n/5 ;
            n/=5;
            
        }
        printf("%lld\n",sum);
    }
    return 0 ;
}
