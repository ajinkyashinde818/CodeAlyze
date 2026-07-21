#include <stdio.h>
#include <string.h>

int main() {
	char x[2], y[2];

	scanf("%c %c", &x[0], &y[0]);

	if (x[0] < y[0]) printf("<\n");
	else if (x[0] > y[0]) printf(">\n");
	else printf("=\n");

	return 0;
}
