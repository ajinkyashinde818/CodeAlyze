#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);

    int cnt = 0;
    int mindata;
    if (a >= b) {
        mindata = b;
    } else {
        mindata = a;
    }

    while (mindata >= 1) {
        
        if (a % mindata == 0 && b % mindata == 0) {
            cnt += 1;
        }

        if (cnt == k) {
            printf("%d", mindata);
            break;
        }
        mindata--;

    }


    return 0;

}
