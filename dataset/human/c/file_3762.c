#include <stdio.h>

int main(void){

    long A = 0;
    long B = 0;
    long min = 0;
    long tmp = 0;
    long C = 0;

    scanf("%ld %ld", &A, &B);

    min = A * B;

    if(A < B){
        int tmp = A;
        A = B;
        B = tmp;
    }

    C = A % B;
    while(C != 0){
        A = B;
        B = C;
        C = A % B;
    }

    printf("%ld\n", min/B);

    return 0;
}
