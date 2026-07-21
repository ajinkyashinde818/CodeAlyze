#include <stdio.h>
#define nMax 1000000000
int main(void){
    int min,i,t,n,rMax;
    min = nMax;
    rMax = -10000000000;
    scanf("%d",&t);
    scanf("%d",&min);	
    for(i=1;i<t;i++){
        scanf("%d",&n);
        if(n-min > rMax)rMax = n-min;
    	if(n < min)min = n;
    }
printf("%d\n",rMax);
return 0;
}
