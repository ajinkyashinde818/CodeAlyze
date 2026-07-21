#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

    int i;
    char s[500000];
    char *w[] = {"dream", "dreamer", "erase", "eraser"};
    char *p, *q;
    bool bMatch;

    scanf("%s", s);

    if ( strlen(s) < 5 ) {
        printf("NO\n");
        return 0;
    }

    p = &s[strlen(s) - 1];

    while (p >= s) {
        bMatch = false;
        for (i = 0; i < 4; i++ ) {
            q = p - strlen(w[i]) + 1;
            if ( q < s ) {
                continue;
            } else if ( !strncmp(w[i], q, strlen(w[i])) ) {
                p -= strlen(w[i]);
                bMatch = true;
                break;
            }

        }
        if ( bMatch == false ) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;

}
