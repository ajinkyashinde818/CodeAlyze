#include <stdio.h>

int main() {
    int i, n, k, h, count=0;
    fscanf(stdin, "%d %d", &n, &k);

    for(i=0;i<n;i++) {
        fscanf(stdin, "%d", &h);
        count += (h>=k?1:0);
    }

    fprintf(stdout, "%d\n", count);

    return 0;
}
