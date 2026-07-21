#include<stdio.h>
int main(){
    int A,B,K,i;
    int count = 0;
    scanf("%d %d %d",&A,&B,&K);
    
    for(i = B ; i > 0 ; i--){
        if(A%i == 0 && B%i == 0){
            count++;
        }
        if(count == K)
            break;
    }
    printf("%d\n",i);
    return 0;
}
