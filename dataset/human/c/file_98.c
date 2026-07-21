#include<stdio.h>


int main(void){
    int count=0;
    int n=0;
    int R=0,G=0,B=0,N=0;
    scanf("%d %d %d %d",&R,&G,&B,&N);
    for(int i=0;i<=N;i++){
        if(i*R>N) break;
        for(int j=0;j<=N;j++){
            if(i*R+j*G>N) break;
            n=N-(i*R+j*G);
            if(n%B==0){
                count++;
            }
        }
    }
    printf("%d\n",count);  
    return 0;
}
