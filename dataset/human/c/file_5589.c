#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int Pow(int n, int m);
int Max(int N[], int n);
int Sum(int N[], int n);

#define St 500

int main()
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("%d", a - b + 1);

	return 0;
}

int Pow(int n, int m) {
	int ret = 1;

	for (int i = 0; i < m; i++) {
		ret *= n;
	}

	return ret;
}

int Max(int N[], int n) {
	int max = 0;

	for (int i = 0; i < n; i++) {
		max = max < N[i] ? N[i]: max;
	}

	return max;
}

int Sum(int N[], int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += N[i];
	}

	return sum;
}
