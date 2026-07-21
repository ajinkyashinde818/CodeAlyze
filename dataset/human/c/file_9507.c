#include<stdio.h>

int main(void)
{
    int N, D, X;
    int a;

    scanf("%d%d%d", &N, &D, &X);
    int eat = X;

    for (int i = 0; N > i; i++) {
        scanf("%d", &a);
        eat += (D - 1) / a + 1;
    }
    printf("%d\n", eat);
}
