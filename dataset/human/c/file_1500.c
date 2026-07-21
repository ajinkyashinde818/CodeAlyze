#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char x;
    char y;

    scanf("%c %c", &x, &y);

    if (x == y) {
        puts("=");
    } else if (x > y) {

        puts(">");

    } else {

        puts("<");

    }
    return 0;

}
