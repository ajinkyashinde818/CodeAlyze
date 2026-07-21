#include <stdio.h>

int main(void){
    int K, N, A0, A, B;
    int distance, diff, max_diff;
    int i;
    distance = 0;
    max_diff = 0;

    scanf("%d%d", &K, &N);
    scanf("%d", &A0);
    A = A0;
    for(i = 0; i < N-1; i++){
        scanf("%d", &B);
        diff = B - A;
        distance += diff;
        if(diff > max_diff)
            max_diff = diff;
        A = B;
    }
    diff = K - B + A0;
    distance += diff;
    if(diff > max_diff)
        max_diff = diff;

    distance -= max_diff;
    printf("%d\n", distance);

    return 0;
}
