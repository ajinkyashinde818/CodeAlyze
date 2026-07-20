/* Example program. */
#include <stdio.h>
typedef struct { int id; float mark; } Record;
int main(void) {
    Record item = { 29, 28.5f };
    printf("%d %.1f\n", item.id, item.mark);
    return 0;
}
