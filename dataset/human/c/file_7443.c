#include<stdio.h>
int main(void){
    int i,j;
    int a[10000];
    for(i=0;i<10000;i++){
        scanf("%d",&a[i]);
        if(a[i]==0){
            break;
        }
    }
    j=i;
    for(i=0;i<j;i++){
        printf("Case %d: %d\n",i+1,a[i]);
    }
    return 0;
}
