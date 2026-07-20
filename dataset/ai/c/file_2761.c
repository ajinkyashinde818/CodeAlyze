#include <stdio.h>
int main(void) {
    for (int row = 1; row <= 4; ++row) {
        for (int column = 1; column <= row; ++column) {
            printf("%d ", column);
        }
        putchar('\n');
    }
    return 0;
}
