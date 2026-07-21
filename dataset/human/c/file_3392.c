#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcut(char *str, const char *seek)
{
    char *p = str;
    if (strncmp(str, seek, strlen(seek)) == 0) {
        p += strlen(seek);
    }
    return p;
}

int solve(char *str)
{
    char *p = str;
    char *k;
    k = strcut(p, "maerd");
    if (k != p) { p = k; }
    k = strcut(p, "remaerd");
    if (k != p) { p = k; }
    k = strcut(p, "esare");
    if (k != p) { p = k; }
    k = strcut(p, "resare");
    if (k != p) { p = k; }
    if (p == str) {
        return 0;
    } else if (strcmp(p, "") == 0) {
        return 1;
    } else {
        return solve(p);
    }
}

int main(void)
{
    char s[100001] = "";
    scanf("%s", s);
    size_t len = strlen(s);
    for (size_t i = 0u; i < len / 2; ++i) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
    puts(solve(s) == 1 ? "YES" : "NO");

    return 0;
}
