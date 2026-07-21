#include<stdio.h>
main(){
    int x,y,i,j;
    while(1){
        scanf("%d %d",&x,&y);
        if(x==0&&y==0)
        break;
        for(i=0;i<x;i++){
        for(j=0;j<y;j++)
        if((i+j)%2==0)
        printf("#");
        else
        printf(".");
        printf("\n");
        }
        printf("\n");
    }
}
