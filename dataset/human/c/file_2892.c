#include <stdio.h>

int main(void) {
    int K, S;
    scanf("%d %d", &K, &S);

    int x, y, z;
    int result = 0;
    for (x = 0; x <= K; x++) {
        for (y = 0; y <=K; y++) {
            z = S - x - y;
            if (z >= 0 && z <= K) {
                result++;
            }
        }
    }
    
    printf("%d\n", result);

    return 0;
}
