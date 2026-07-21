#include <stdio.h>
int main(void){
    int i,n;
    long max,min;
    long R2,R1,Rt;
    
    scanf("%d",&n);
    
    scanf("%ld",&R1);
    scanf("%ld",&R2);
    
    max=R2-R1;
    min=R1;
    Rt=R2;
    
    for(i=2; i<=n; i++){
        if(i!=2)scanf("%ld",&Rt);
        if(max < Rt-min) max=Rt-min;
        if(min > Rt) min=Rt;
    }
    
    printf("%ld\n",max);
    return 0;
}
