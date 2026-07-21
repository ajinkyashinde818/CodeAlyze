#include <string.h>
#include <stdio.h>
#define REP(a) for(i = 0; i < a; i++)

int main(void) {
    int i,j;
    char a[105],b[105],tmp;
    scanf("%s",a);
    scanf("%s",b);
    REP(strlen(a)) {
        for (j = i + 1; j < strlen(a); j++) {
            if (a[i] > a[j]) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    REP(strlen(b)) {
        for (j = i + 1; j < strlen(b); j++) {
            if (b[i] < b[j]) {
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }
    if (strcmp(a, b) < 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
