#define _CRT_SECURE_NO_WARNINGS

//#define DEBUG
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main() {
#ifdef DEBUG

#endif
	char X, Y;
	scanf("%c %c", &X, &Y);
	if (X > Y) {
		printf(">\n");
	}
	else if (X < Y) {
		printf("<\n");
	}
	else {
		printf("=\n");
	}

	
}
