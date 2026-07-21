#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#define true 1
#define false 0

int l;
int s;
int x, y, z;

int main() {
	int ans = 0;
	scanf("%d %d", &l, &s);
	for (int i = 0; i <= l; i++) {
		for (int j = i; j <= l; j++) {
			for (int k = j; k <= l; k++) {
				if (i + j + k == s) {
					if (i == k && k == j) {
						ans++;
					}
					else if (i != k && k != j && i != j) {
						ans += 6;
					}
					else {
						ans += 3;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
