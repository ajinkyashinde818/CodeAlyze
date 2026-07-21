#include <stdio.h>

int main()
{
	int a, b, c;
	char S[4];
	scanf("%s", S);
	a = S[0] - 'a';
	b = S[1] - 'a';
	c = S[2] - 'a';
	if (a * b * c == 0 && a + b + c == 3 && a * b + b * c + c * a == 2) printf("Yes\n");
	else printf("No\n");
	fflush(stdout);
	return 0;
}
