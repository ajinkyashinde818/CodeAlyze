#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n,cnt;
	while (fscanf(stdin, "%d", &n),n!=0) {
		cnt = 0;
		while (n != 1)
			if (n % 2 == 0) n /= 2, cnt++;
			else n *= 3, n += 1, cnt++;
		fprintf(stdout, "%d\n", cnt);
	}
	return 0;
}
