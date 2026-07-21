#include <stdio.h>

int main(void)
{

    int n, a[101] = {0}, k = 0, h, m = 0, i, j;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(k < a[i])
            k = a[i];
    }

    for(i = k; i > 0; i--) {
        for(j = 0; j < n; j++) {
            if(a[j] >= i)
                m++;
        }
        if(m >= i) {
            h = i;
            break;
        }
        m = 0;
    }

    printf("%d\n", h);

    return 0;
}
