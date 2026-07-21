#include<stdio.h>
int main(){
    int x,k,a=0;
    scanf("%d %d",&x,&k);
    int n[x];
    for(int i=0;i<x;i++){
        scanf("%d",&n[i]);
        if(n[i]>=k){
            a++;
        }
    }
    printf("%d\n",a);
    return 0;
}
