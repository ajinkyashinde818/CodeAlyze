#include <stdio.h>
#include <string.h>

int main(void)
{
	char S[3];

	scanf("%s", S);

	if (strcmp(S, "abc") == 0) printf("Yes");
	else if (strcmp(S, "acb") == 0) printf("Yes");
	else if (strcmp(S, "bca") == 0) printf("Yes");
	else if (strcmp(S, "bac") == 0) printf("Yes");
	else if (strcmp(S, "cab") == 0) printf("Yes");
	else if (strcmp(S, "cba") == 0) printf("Yes");
	else printf("No");

	return 0;
}
