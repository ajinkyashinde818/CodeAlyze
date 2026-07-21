#include<stdio.h>
int main(void){
    int A,B,K;
    scanf("%d %d %d",&A,&B,&K);
    if(A < B){
        int w = A;
        A = B; B = w;
    } //A > B
    int r[B];
    int j;
    for(int i = 1; i <= B; i++){
        if(A%i == 0 && B%i == 0){
            r[j] = i; j++;
            // printf("r[%d] = %d\n",j,i);
        }
    }
    // printf("j = %d\n",j);
    printf("%d\n",r[j-K]);
    return 0;
}
