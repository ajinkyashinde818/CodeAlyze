#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n;

    scanf("%d", &n);
    while (n--) {
        double m, dec;
        int x, v, md;
        char buf[10];
        md = (int)pow(2, 8);
        m = 2 * md * md;
        v = 0;
        for (int i = 0; i < 4; i++) {
            scanf("%2x", &x);
            if (i == 0) {
                if (x & 0x80) putchar('-');
                x = x & 0x7f;
            }
            if (i <= 2) {
                v += x * m;
            }
            else {
                v += (x & 0x80) > 0;
                printf("%d", v);
                x = x & 0x7f;
                if (x > 0) {
                    sprintf(buf, "%.7g", (double)x * m);
                    printf("%s\n", &buf[1]);
                }
                else {
                    printf(".0\n");
                }
            }
            m /= md;
        }
    }

    return 0;
}
