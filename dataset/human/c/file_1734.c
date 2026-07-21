#include <stdio.h>

unsigned int a[21];
unsigned int b[21];
unsigned int c[21];

int main(void)
{
    unsigned int n;
    unsigned int i;
    unsigned int ret = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    for (i = 0; i < (n - 1 ); i++) scanf("%d", &c[i]);

    for (i = 0; i < n; i++) {
        ret += b[a[i] - 1];
        if ((i < (n - 1 )) && (a[i + 1] == (a[i] + 1))) {
            ret += c[a[i] - 1];
        }
    }

    printf("%d", ret);

    return 0;
}
