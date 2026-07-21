#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, k;
    char *s, p, *t;
    scanf("%d", &n);
    s = malloc(n+1);
    scanf("%s", s);
    scanf("%d", &k);
    p = s[k-1];
    t = s;
    while(*t != '\0'){
        if(*t != p) *t = '*';
        t++;
    }
    printf("%s\n", s);
    return 0;
}
