#include <stdio.h>

int main(void){
    int N, K;
    int counter = 0;
    scanf("%d %d", &N, &K);
    int h[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &h[i]);
        if (h[i] >= K){
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}
