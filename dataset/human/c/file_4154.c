#include <stdio.h>

int main(void)
{
    int A, B, K, i;
    scanf("%d%d%d", &A, &B, &K);

    int min = A < B ? A : B;

    int cnt = 0;
    for (min; min > 0; min--)
    {
        if(A % min == 0 && B % min == 0){
            cnt++;
            if(cnt == K){
                printf("%d\n", min);
                return 0;
            }
        }
    }
}
