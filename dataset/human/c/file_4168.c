#include<stdio.h>

int main(){
    int A, B, K, tmp;
    int ans=0, i, j;

    scanf("%d %d %d", &A, &B, &K);

    if(A<B){
        tmp = A;
        A = B;
        B = tmp;
    }

    for(i=B; i>0; i--){
        if((A%i + B%i) == 0){
            ans += 1;
        }
        if(ans == K){
            break;
        }
    }
    printf("%d", i);

    return 0;
}
