#include <stdio.h>

int main()
{
 int A;
 int B;
 int K;
 int i;
 int maxnum;
 int count=0;
 scanf("%d %d %d",&A,&B,&K);

 maxnum=A;
 if(A>B) maxnum=B;

 for(i=maxnum;i>=1;i--)
 {
   if( ((A%i)==0)&&((B%i)==0)) count++;
   if(count==K)
   {
    printf("%d\n",i);
    break;
   }
 }

 return 0;
}
