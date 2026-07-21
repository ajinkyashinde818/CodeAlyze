#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i, x[100000], n;
    i=0;
    while (1) {
        i++;
        scanf("%d", &x[i]);
        if (x[i]==0) {
            break;
        }
    }
    for (n=1; n<i; n++) {
        printf("Case %d: %d\n", n, x[n]);
    }
    return 0;
}
