#include <stdio.h>

const char *mcxi = "mcxi";

int integer(char *s)
{
    int n;
    int i;
    int tmp = 1;

    for (n = i = 0; s[i]; i++){
        if ('2' <= s[i] && s[i] <= '9') tmp = s[i] - '0';
        else {
            switch (s[i]){
                case 'm': n += tmp * 1000; break;
                case 'c': n += tmp * 100; break;
                case 'x': n += tmp * 10; break;
                case 'i': n += tmp; break;
            }
            tmp = 1;
        }
    }
    return n;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    while (n-- > 0){
        char s1[32], s2[32];
        int n1, n2;
        int i;
        int digit;
        int ten;

        scanf("%s %s", s1, s2);
        n1 = integer(s1);
        n2 = integer(s2);
        n1 += n2;
        for (digit = 0, ten = 1000; n1 > 0; ten /= 10, digit++){
            switch (n1 / ten){
                case 0: break;
                case 1:
                    putchar(mcxi[digit]);
                    n1 -= ten;
                    break;
                default:
                    putchar(n1 / ten + '0');
                    putchar(mcxi[digit]);
                    n1 -= (n1 / ten) * ten;
                    break;
            }
        }
        puts("");
    }

    return 0;
}
