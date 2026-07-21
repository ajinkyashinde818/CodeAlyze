#include<stdio.h>
#include<string.h>
int main() {

	
	
	char s[11];
	int i, k, n;

	scanf("%d",&n);
	scanf("%s", s);
	scanf("%d", &k);

	for (i = 0; i < n; i++) {
		if (s[k - 1] != s[i])
			s[i] = '*';

	}
	printf("%s", s);
	return 0;

}
