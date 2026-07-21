#include<stdio.h>

int main(void){

    int K,S,i,j,k,result=0;

    scanf("%d %d",&K,&S);

    for(i = 0;i <= K;i++){
        for(j = 0;j <= K;j++){
            k = S - i - j;
            if(k >= 0 && k <= K){
                //printf("%d %d %d\n",i,j,k);
                result++;
            }
        }
    }

    printf("%d",result);
    return 0;
}
