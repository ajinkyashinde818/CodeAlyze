#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i, j;
     
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        unsigned intp, decp;
        double dec;
        int hex, max;

        scanf("%x", &hex);
        intp = (hex >> 7) & 0xFFFFFF;
        decp = hex & 0x7F;

        dec = max = 0;
        for (j = 0; j < 7; j++){
            if (decp & (1 << (6 - j))){
                dec += pow(.5, j + 1);
                max = j;
            }
        }
        if (hex < 0) putchar('-');
        printf("%.*lf\n", max + 1, intp + dec);
    }

    return (0);
}
