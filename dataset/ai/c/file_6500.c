#include <stdio.h>
typedef struct { int id; float mark; } Record;
int main(void) {
	Record item = { 36, 23.5f };
	printf("%d %.1f\n", item.id, item.mark);
	return 0;
}
