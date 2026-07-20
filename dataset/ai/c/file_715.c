#include <stdio.h>
int main(void) {
    int result = 54;
    printf("%d %c\n", result, 'A' + result % 26);
    return 0;
}
