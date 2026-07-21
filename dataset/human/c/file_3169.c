#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    long int n;
    long int k;
    long int h,i,j;
    long int a,b,c;
    long int dis;
 

    scanf("%ld%ld",&k,&n);

   long int max=0;

   scanf("%ld%ld",&a,&b);

   dis = b-a;
   max= dis;

   for(int i=0;i<n-2;i++){
       scanf("%ld",&c);
       dis = c-b;
       b=c;
       if(dis>max)
        max=dis;
   }

   dis = a+k-c;

   if(dis>max)
    max=dis;

    printf("%ld",k-max);


	return 0;
}
