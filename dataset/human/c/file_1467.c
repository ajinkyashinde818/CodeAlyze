#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
#ifdef DEBUG
	printf("");
#endif
	int N;
	int tmp;
	int flag = 0;

	scanf("%d", &N);
	tmp = N % 10;
	if (tmp == 9) {
		flag = 1;
	}
	tmp = N / 10;
	if (tmp == 9) {
		flag = 1;
	}
	if (flag) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
}
