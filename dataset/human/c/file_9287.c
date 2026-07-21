#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int i;
    int count = 0;
    for(i=0; i<N; i++) {
        int temp;
        scanf("%d", &temp);
        if(temp >= K) count++;
    }
    printf("%d\n", count);
    return 0;
}
