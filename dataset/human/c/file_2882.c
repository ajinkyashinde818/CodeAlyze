#include <stdio.h>
int main(void) {
    int k, s, count = 0;
    scanf("%d%d", &k, &s);
    for(int x = 0; x <= k; x++) {
        for(int y = 0; y <= k; y++) {
            int z = s - x - y;
            if(z >= 0 && z <= k) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
