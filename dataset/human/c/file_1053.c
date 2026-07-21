#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char  s[100];
	char arr[] = "FESTIVAL";
	char * s_1 = arr;
	int i;
	scanf("%s", s);
	i = strlen(s) - strlen(s_1);
	for(int k=0; k<i; k++){
		printf("%c",s[k]);			
	}

	return 0;
}
