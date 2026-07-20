#include <stdio.h>
int main(void) {
    int value = 63;
    printf("%d %c\n", value, 'A' + value % 26);
    return 0;
}
