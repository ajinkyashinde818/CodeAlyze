#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void) {
    bool judge = false;
    int count = 0, n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        if (a == b) count++;
        else count = 0;
        if (count >= 3) judge = true;
    }
    if (judge) printf("Yes\n");
    else printf("No\n");

    return 0;
}
