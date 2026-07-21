#include <stdio.h>
int main(void) {
    long aa, bb, a, b, tmp, r;
    scanf("%ld", &aa);
    scanf("%ld", &bb);


    if (aa<bb) {
        tmp = aa;
        aa = bb;
        bb = tmp;
    }
    a=aa;
    b=bb;

    r = a%b;
    while (r!=0) {
        a = b;
        b = r;
        r = a%b;
    }

    printf("%ld", aa*bb/b);
    return 0;
}
