#include<stdio.h>

int main(void)
{
    long long A, B,x;
    long long r;

    scanf("%lld %lld", &A, &B);

    x = A * B;
    

    if (A < B) {
        r = A;
        A = B;
        B = r;
    }
    r = A % B;

    while (r != 0) {
        A = B;
        B = r;
        r = A % B;
    }

    //printf("for debug B is %d, A is %d\n", B,A);

    printf("%lld", x/B);



        return 0;

}
