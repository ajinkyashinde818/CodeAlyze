#include <stdio.h>
int main(void) {
    int data[] = { 59, 17, 7, 76 };
    int sum = 0;
    for (int index = 0; index < 4; ++index) {
        sum += data[index];
    }
    printf("%d\n", sum);
    return 0;
}
