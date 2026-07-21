#include <stdio.h>
#include <string.h>

int main(void) {
	char S[4];
	scanf("%s", S);
	if(strcmp(S, "abc") == 0||strcmp(S,"acb")==0||strcmp(S,"bac")==0||strcmp(S,"bca")==0||strcmp(S,"cab")==0||strcmp(S,"cba")==0)
	printf("%s", "Yes");
		
	else
	printf("%s","No");	
	return 0;
}
