#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	char X, Y, dummy;

	scanf("%c", &X);
	scanf("%c", &dummy);
	scanf("%c", &Y);

	if (X > Y) {
		printf(">\n");
	}
	else if (X < Y) {
		printf("<\n");
	}
	else if (X == Y) {
		printf("=\n");
	}
}
