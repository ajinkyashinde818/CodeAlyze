#include<stdio.h>
int main(void){
    int N,D,X,i,j;
    scanf("%d %d %d",&N,&D,&X);
    int A[N],sum=N;
    for(i=0;N>i;++i)
    scanf("%d",&A[i]);
    /*入力*/
    for(i=0;N>i;++i){
        for(j=1;A[i]*j+1<=D;++j){
            ++sum;
        }
    }
    printf("%d",sum+X);
    return 0;
}
