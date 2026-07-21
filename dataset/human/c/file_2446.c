#include <stdio.h>
#include <string.h>

int main()
{
	char S[4];
	
	scanf("%s",&S);
	if(!strcmp(S,"abc") || !strcmp(S,"acb") || !strcmp(S,"bac") || !strcmp(S,"bca") || !strcmp(S,"cab") || !strcmp(S,"cba")) printf("Yes\n");
	else printf("No\n");
	
	return 0;
}
