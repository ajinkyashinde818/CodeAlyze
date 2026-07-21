#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool compare(const char *s, const char *t, size_t len)
{
    for (int i = len - 1; 0 <= i; i--) {
        if (*s != t[i]) return false;
        s--;
    }
    return true;
}

int main(int argc, char **argv)
{
    char s[100002] = {'\0'};
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (char *i = s + n; *i; i--) {
        if (compare(i, "dream", 5)) {
            i -= 4;
        } else if (compare(i, "dreamer", 7)) {
            i -= 6;
        } else if (compare(i, "erase", 5)) {
            i -= 4;
        } else if (compare(i, "eraser", 6)) {
            i -= 5;
        } else {
            printf("NO\n");
            return EXIT_SUCCESS;
        }
    }
    printf("YES\n");
    return EXIT_SUCCESS;
}
