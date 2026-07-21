#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main() {
	int k, s;
	scanf("%d%d", &k, &s);
	int a, b, c=0;
	int cnt=0;
	for (a = 0; a <= k; a++) {
		for (b = 0; b <= k; b++) {
			c = s - a - b;
			if (c >= 0 && c <= k) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);


}
