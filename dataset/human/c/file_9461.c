#include<stdio.h>

int main() {
	int n, d, x, cnt, i, temp, val;
	
	val = scanf("%d%d%d", &n, &d, &x);
	if (val == 0) return 1;

	cnt = x;
	for (i = 0; i < n; i++) {
		val = scanf("%d", &temp);
		if (val == 0) return 1;
		cnt += (d - 1) / temp + 1;
	}
 
	printf("%d", cnt);
	return 0;
}
