#include <stdio.h>
#include <algorithm>


const int kN = 100000 + 5;
int n, a[kN];


int main()
{
    int result = 0;
    int last = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        int b = 0;
        while (a[i] >> b + 1) ++ b;
        int c = a[i] != (1 << b);
        b += c;
        if (last >= b) {
            last = b - c;
        } else {
            result += b - last;
            last = b;
        }
        // printf("(%d, %d %d %d)\n", a[i], b, c, result);
    }
    printf("%d\n", result);

}
