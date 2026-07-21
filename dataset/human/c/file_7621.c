#include <stdio.h>
int main(void){
    int i,x;
        for(i=1;i<=10000;i++){
        scanf("%d",&x);
    if(1<=x&&x<=10000){
         printf("Case %d: %d\n",i,x);
    }else if(x<1&&10000<x){
       break;
    }
    }
        return 0;
    }
