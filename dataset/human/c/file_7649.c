#include<stdio.h>

int main(void){
    int x[10001];
    int num;
    int m;
    for(int i=0;i<=10000;i++){
        scanf("%d",&num);
        x[i]=num;
        m=i;
        if(num==0){
            break;
        }
    }
    for(int k=1;k<=m;k++){
        printf("Case %d: %d\n",k,x[k-1]);
    }
    return 0;
}
