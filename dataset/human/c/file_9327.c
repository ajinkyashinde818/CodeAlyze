#include<stdio.h>
int main(void){
    int n,k;
    int height[100000];
    scanf("%d %d",&n,&k);
    int i=0,sum = 0;
    for(i=0;i<n;i++){
        scanf("%d",&height[i]);
    if(k <= height[i]){
        sum = sum + 1;
    }
    }
    printf("%d\n",sum);
    return 0;
}
