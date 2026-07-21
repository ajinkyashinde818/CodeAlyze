#include<stdio.h>
int main(void){
    int A,B,K,R[100];
    R[0]=1;
    int k=1;
    scanf("%d %d %d",&A,&B,&K);
    for (int i=2; i<=100; i++) {
        if(A%i==0 && B%i==0){
            R[k]=i;
            k++;
        }
    }
    k-=K;
    printf("%d\n",R[k]);
    return 0;
}
