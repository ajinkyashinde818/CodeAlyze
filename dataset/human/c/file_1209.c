#include <stdio.h>
#include <string.h>

int main()
{
    char s[101], t[101], tmp;
    int i, j;
    scanf("%s %s", s, t);
    for (i=strlen(s)-2; i>=0; i--)
    {
        for (j=0; j<=i; j++)
        {
            if (s[j] > s[j+1]) {
                tmp = s[j+1];
                s[j+1] = s[j];
                s[j] = tmp;
            }
        }
    }
    for (i=strlen(t)-2; i>=0; i--)
    {
        for (j=0; j<=i; j++)
        {
            if (t[j] < t[j+1]) {
                tmp = t[j+1];
                t[j+1] = t[j];
                t[j] = tmp;
            }
        }
    }
    if (strcmp(s,t) < 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
