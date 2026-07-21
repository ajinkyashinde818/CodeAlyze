#include <stdio.h>
#include <string.h>

int main(void)
{
    size_t n, m;
    scanf("%zu %zu", &n, &m);
    char a[n + 1][n + 1];
    for (size_t i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (size_t i = 0; i < m; ++i) {
        char b[m + 1];
        scanf("%s", b);
        if (strstr(a[i], b) == NULL) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
