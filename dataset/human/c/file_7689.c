#include<stdio.h>
int main(void){
    int x[10001],i=1;
    while (1){
    scanf("%d",&x[i]);
    if(x[i]==0)break;
    i++;
    }
    i=1;
    while (1){
    if(x[i]==0)break;
    printf("Case %d: %d\n",i,x[i]);
    i++;
    }
    return 0;
}
