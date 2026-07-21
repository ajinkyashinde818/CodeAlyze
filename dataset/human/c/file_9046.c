#include <stdio.h>

int main (void)
{
    int N, K;
    int h[100000];
    scanf("%d%d", &N, &K);
    int i;
    int num = 0;
    for (i = 0; i < N; i++) {
        scanf("%d", &h[i]);
        if (h[i] >= K) num++;
    }
    
    printf("%d", num);

    return 0;
}
