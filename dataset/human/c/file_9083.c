#include<stdio.h>
int main()
{
   long long int N,K,s[100000],i,x=0;
   scanf("%lld%lld",&N,&K);

   for(i=0;i<N;i++)
   {

      scanf("%lld",&s[i]);

      if(s[i]>=K)
      {
         x=x+1;
       }
    }
    printf("%lld",x);
    return 0;
}
