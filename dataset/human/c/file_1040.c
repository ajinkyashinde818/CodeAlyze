#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	char *S = (char *)malloc(sizeof(char) * 100);
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){}
	S[i - 8] = '\0';
	printf("%s\n", S);
	return 0;
}
