#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
	int n, k;
	char s[11];
	char c;
	
	scanf("%d %s %d", &n, &s[0], &k);
	c = s[k-1];
	
	for (int i = 0; i < n; i++) {
		if (s[i] != c)
			printf("*");
		else
			printf("%c", s[i]);
	}
	
	
	return 0;
}
