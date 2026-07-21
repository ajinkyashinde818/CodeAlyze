#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
long long cmpfunc (const void * a, const void * b) {
   return ( *(long long*)a - *(long long*)b );
}



int main(void){
   
long long int test,i,j,n,count,flag=0,o1=0,o2=0,b1,x,m,l,max,sum2,min,f,c,r,o,sum1,sum=0,y,a,b,count1=0,a2,b2, k;
scanf("%lld%lld",&n,&k);
count=0;
for(i=0;i<n;i++){
    scanf("%lld",&a);
    if(a>=k){
        count++;
    }
}
printf("%lld",count);
return 0;
}
