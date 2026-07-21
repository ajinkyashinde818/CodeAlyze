#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int n, a, b, c;
    scanf("%d", &n);

    int arr01[n];
    int arr03[n - 1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        arr01[i] = a;
    }

    int mysum = 0;
    for (int j = 0; j < n; j++) {
        scanf("%d", &b);
        mysum += b;
    }

    for (int k = 0; k < n - 1; k++) {
        scanf("%d", &c);
        arr03[k] = c;
    }

    for (int l = 0; l < n - 1; l++) {

        int first = arr01[l];
        int second = arr01[l + 1];

        if (first + 1 == second) {
            mysum += arr03[first - 1];
        }

    }

    printf("%d\n", mysum);

    return 0;

}
