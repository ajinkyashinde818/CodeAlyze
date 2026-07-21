#include <stdio.h>
#include <string.h>

#define N 100

int main(void)
{
    char s[N] = "\0";
    char t[N] = "\0";
    char c;

    gets(s);
    gets(t);

    int i;
    int j;
    for (i = 0;i < N && s[i] != '\0';i++) {
        for (j = i + 1;j < N && s[j] != '\0';j++) {
            if (s[i] > s[j]) {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
            }
        }
    }
    for (i = 0;i < N && t[i] != '\0';i++) {
        for (j = i + 1;j < N && t[j] != '\0';j++) {
            if (t[i] < t[j]) {
                c = t[i];
                t[i] = t[j];
                t[j] = c;
            }
        }
    }

    if (strcmp(s, t) < 0) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}
