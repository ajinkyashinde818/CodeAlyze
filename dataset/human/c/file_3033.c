#include <stdio.h>
#include <stdlib.h>
#define STR_LENGTH (6)
int main(int argc, char* argv[])
{
	//ABC160 C
	int i;
	int k, n;
	int *a;
	int kyori = 0x7fffffff;
	int m;//目的地
	// 1周 Kメートルの円
	// N軒の家
	// 北端からA1メートルのとこに家、北端からA2メートルのとこに家　繰り返し
	// K N
	// A1 A2 A3 A4 A5
	scanf("%d %d\n", &k, &n);

	a = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d ", &a[i]);
	}

	i = 0;
	//右
	m = n - 1;
	if (kyori > a[m] - a[i]) {
		kyori = a[m] - a[i];
	}
	//左
	m = 1;
	if (kyori > a[m] - a[i] + k) {
		kyori = a[m] - a[i] + k;
	}

	for (i = 1; i < n - 1; i++) {
		//右
		m = i - 1;
		if (kyori > a[i] - a[m] + k) {
			kyori = a[i] - a[m] + k;
		}

		//左
		m = i + 1;
		if (kyori > a[i] - a[m] + k) {
			kyori = a[i] - a[m] + k;
		}

	}

	i = n - 1;
	m = i - 1;
	//右
	if (kyori > a[i] - a[m] + k) {
		kyori = a[i] - a[m] + k;
	}

	m = 0;
	//左
	if (kyori > a[i] - a[m]) {
		kyori = a[i] - a[m];
	}

	printf("%d", kyori);

	return 0;
}
