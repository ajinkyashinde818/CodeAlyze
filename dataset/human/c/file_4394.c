#include <stdio.h>

int main(void) {

    int n, a, b;

    scanf("%d", &n);

    int c = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        if (a == b)
            c++;
            
        if (c >= 3)
            break;   

        if (a != b)
            c = 0;
    }

    if (c >= 3)
        printf("Yes\n");

    if (c < 3)
        printf("No\n");

    return 0;
}
