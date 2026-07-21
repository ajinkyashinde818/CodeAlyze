#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	int a, b;
	scanf("%c %c", &a, &b);
	if (a < b) printf("<\n");
	else if (a == b) printf("=\n");
	else printf(">\n");

	return 0;
}
