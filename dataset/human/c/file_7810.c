#include <stdio.h>

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        int k;
        int p;
        scanf("%d %d", &k, &p);
        int res = k % p;
        if (res == 0) {
            printf("%d\n", p);
        } else {
            printf("%d\n", res);
        }
    }
    
    return 0;
}
