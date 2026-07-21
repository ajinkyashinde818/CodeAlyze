#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rev(char *s) {
    int l = strlen(s), i;
    for (i=0;i<l/2;i++) {
        char t = s[i];
        s[i] = s[l-1-i];
        s[l-1-i] = t;
    }
}

char T[4][8] = {"dream", "dreamer", "erase", "eraser"};

int main(void) {
    
    int i, c, l;
    char s[100001];
    for(i=0;i<4;i++)rev(T[i]);
    scanf("%s", s);
    l = strlen(s);
    rev(s);
    for (;c<l;) {
        int k = -1;
        for (i=0;i<4;i++) {
            if (!strncmp(s+c, T[i], strlen(T[i]))) {
                k = strlen(T[i]);
                break;
            }
        }
        if (k<0) {
            printf("NO\n");
            return 0;
        } 
        c += k;
    }
    printf("YES\n");
    return 0;
}
