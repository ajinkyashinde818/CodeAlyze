#include<stdio.h>
int main(void){
    int a,b,N,i,ren = 0;
    scanf("%d",&N);
    
    for(i = 0;i < N;i ++){
        scanf("%d %d",&a,&b);
        if(a == b){
            ren ++;
        }else{
            ren = 0;
        }
        if(ren == 3){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
