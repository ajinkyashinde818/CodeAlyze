#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n[3] = { 0 };
	int n2 = 0;
	int n3 = 0;
	int eaten = 1;
	scanf("%d%d%d", &n[0], &n[1], &n[2]);
	if (n[2] <= n[0] + n[1])
		printf("%d", n[1] + n[2]);
	else
		printf("%d", n[0]+n[1]+1+n[1]);
	return 0;
}
