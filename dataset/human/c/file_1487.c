#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char a, b,output;
	scanf("%c %c", &a, &b);
	if (a < b)output = '<';
	else if (a == b) output = '=';
	else output = '>';

	printf("%c", output);
	return 0;
	
}
