#include <stdio.h>
#include <ctype.h>

int main(void)
{
    const char* x="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n;
    while (scanf("%d", &n), n) {
        char s[128], res[128];
        int i, k[128];
        for(i=0;i<n;++i) scanf("%d", k+i);
        scanf("%s", s);
        for(i=0;s[i];++i)
            res[i]=x[(s[i]-(islower(s[i])?'a':('A'-26))-k[i%n]+52)%52];
        res[i]=0;
        puts(res);
    }
    return 0;
}
