#include <stdio.h>
#define N 100000

int main(void) {

    int i, j;
    int num[N];

    for (i = 0; i < N; i++) {
        num[i] = 0;
    }

    scanf("%d", &num[0]);
    i = 1;
    while (num[i - 1] != 0) {
        scanf("%d", &num[i]);
        i++;
    }
    j = i;

    for (i = 0; i < j - 1; i++) {
        printf("Case %d: %d\n", i + 1, num[i]);
    }

    return 0;

}
