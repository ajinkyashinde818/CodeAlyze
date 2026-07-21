#include<stdio.h>
int main()
{
   int N,A[60],B[60],C[60],i,sum=0;
   scanf("%d",&N);
   for(i=0;i<N;i++)
   {
     scanf("%d",&A[i]);
   }
   for(i=0;i<N;i++)
   {
     scanf("%d",&B[i]);

   }
   for(i=0;i<N-1;i++)
   {
     scanf("%d",&C[i]);
     C[N-1]=0;
   }
   for(i=0;i<N;i++)
   {
     if((A[i]-A[i-1])==1 && A[i]!=1)
     {
          sum=sum+B[A[i]-1]+C[A[i]-2];
     }
     else
     {
          sum=sum+B[A[i]-1];
     }
   }
   printf("%d",sum);
   return 0;
}
