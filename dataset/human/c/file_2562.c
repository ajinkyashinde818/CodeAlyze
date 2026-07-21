#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int i;
	int a = 0,b = 0,c = 0;
	char S[3];
	scanf("%s",S);

	for(i = 0;i < 3; ++i){
		if(S[i] == 'a')	++a;
		else if(S[i] == 'b')	++b;
		else ++c;
	}
	if(a == 1 && b == 1 && c == 1)	printf("Yes\n");
	else printf("No\n");

	return 0;
}
