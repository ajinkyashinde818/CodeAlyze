#include<stdio.h>
#include<stdlib.h>

int main(void){
    int A, B, K;
    scanf("%d%d%d", &A, &B, &K);

    int count = 0;
    int i;
    if(A >= B) {
        i = B;
    }
    else{
        i = A;
    }

    while(i > 0){
        if(A % i == 0 && B % i == 0) {
            count++;
            if(count == K) {
                printf("%d\n", i);
                return 0;
            }
        }
        i--;
    }
    return 0;
}
