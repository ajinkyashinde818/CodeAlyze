#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {

    int n, r;
    scanf("%d %d", &n, &r);

    printf("%d", (n >= 10 ? r : r + 100 * (10 - n)));


    return 0;

}
