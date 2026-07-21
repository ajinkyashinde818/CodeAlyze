#include<stdio.h>

int main(){
    int K,S,t=0;
    scanf("%d%d",&K,&S);
    for(int i=0;i<=K;i++){
        for(int j=0;j<=K;j++){
           if(i+j<=S && i+j+K>=S){
               t++;
           }
        }
        
    }
    printf("%d",t);

    return 0;
}
