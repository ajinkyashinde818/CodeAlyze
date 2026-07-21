#include <stdio.h>
#include <string.h>

int main(void){
int n, i, j, k, S, t;
char s[9];
    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        S=0;
        for (j=1; j<=2; j++) {
            scanf("%s", s);
            t=1;
            for (k=0; k<strlen(s); k++) {
                if (s[k] == '2') t=2;
                if (s[k] == '3') t=3;
                if (s[k] == '4') t=4;
                if (s[k] == '5') t=5;
                if (s[k] == '6') t=6;
                if (s[k] == '7') t=7;
                if (s[k] == '8') t=8;
                if (s[k] == '9') t=9;
                if (s[k] == 'm') {
                S+=1000*t;
                t=1;
                }
                if (s[k] == 'c') {
                    S+=100*t;
                    t=1;
                }
                 if (s[k] == 'x') {
                    S+=10*t;
                    t=1;
                }
                if (s[k] == 'i') {
                    S+=t;
                    t=1;
                }
            }
        }
        if (S/1000 != 0) {
            if (S/1000 != 1) printf("%d", S/1000);
            printf("m");
        }
        if (S/100%10 != 0) {
            if (S/100%10 != 1) printf("%d", S/100%10);
            printf("c");
        }
        if (S/10%10 != 0) {
            if (S/10%10 != 1) printf("%d", S/10%10);
            printf("x");
        }
        if (S%10 != 0) {
            if (S%10 != 1) printf("%d", S%10);
            printf("i");
        }
        printf("\n");
    }
    return 0;
}
