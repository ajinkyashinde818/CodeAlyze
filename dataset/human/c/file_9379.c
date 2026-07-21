#include<stdio.h>
int main(void)
{
    int N, D, X, i, A[100], a, c;
    scanf("%d%d%d", &N, &D, &X);
    for(i=0; i<N; i++)
    scanf("%d", &A[i]);
    c = 0;
    for(i=0; i<N; i++)
       c = (D-1) / A[i] + c;
    a = c + 1*N + X;
    printf("%d\n", a);
    return 0;
}
