#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int A, B, K;
    scanf("%ld %ld %ld", &A, &B, &K);
    int ans, i, counter = 0;
    i = A + 1;
    while(counter < K)
    {
        i --;
        //printf("%d, %d, %d\n", i, A % i, B % i);
        if(A % i == 0 && B % i == 0){
            counter ++;
        }
    }
    ans = i;
    printf("%ld", ans);
    return 0;
}
