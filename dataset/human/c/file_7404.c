#include<stdio.h>

int main(){
    int x[10000];
    int max=0;
    for(int i=0;i<10000;i++){
        scanf("%d",&x[max]);
        if(x[max]==0){
            break;
        }
        max++;
    }
    for(int i=0;i<max;i++){
        printf("Case %d: %d\n",i+1,x[i]);
    }
    return 0;
}
