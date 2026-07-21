#include <stdio.h>
#include <stdlib.h>

int roopCount(int days, int up) {
    int cnt = 0;
    for (int i = 0; i < days; i += up) cnt++;
    return cnt;
}

int main() {
    int num;
    scanf("%d", &num);

    int days, r;
    scanf("%d %d", &days, &r);

    int *span;
    span = malloc(sizeof(int) * num + 1);
    for (int i = 0; i < num; i++) scanf("%d", &span[i]);

    int entity = 0;
    for (int i = 0; i < num; i++) entity += roopCount(days, span[i]);

    printf("%d\n", entity + r);

    return 0;
}
