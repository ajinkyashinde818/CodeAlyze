#include <stdio.h>
int main(){
    int N,D,X,i,sum;
    int A[101];
    scanf("%d¥n",&N);
    scanf("%d",&D);
    scanf("%d¥n",&X);
    sum = X;
    for(i = 1; i<=N;i++){scanf("%d¥n",&A[i]);
        if(D%A[i]  ==0){sum +=D/A[i];
        }else{ sum +=(D/A[i]+1);
        }}
    printf("%d",sum);
}
