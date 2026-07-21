#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);

    int *a = (int *) malloc(sizeof(int)*n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    int i = 1;
    for (int step = 1; step <= n; ++step) {
        if (a[i] == 2) {
            printf("%d\n", step);
            return 0;
        }
        i = a[i];
    }
    puts("-1");
    return 0;
}
