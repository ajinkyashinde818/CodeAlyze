#include <stdio.h>
void add_one(int *item) {
    ++*item;
}
int main(void) {
    int value = 4;
    add_one(&value);
    printf("%d\n", value);
    return 0;
}
