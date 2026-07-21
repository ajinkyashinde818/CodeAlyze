#include<stdio.h>

main(void)
{

    int i,roop=0;
    int x[10000];
    for(i=0;i<10000;i++){
        roop++;
        scanf("%d",&x[i]);
        if(x[i]==0) break;
    }
    for(i=0;i<roop;i++){
        printf("Case %d: %d\n",i+1,x[i]);
    }
}
