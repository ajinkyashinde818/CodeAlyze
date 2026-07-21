#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int counter=0;
	char str[3];
	fgets(str, 3, stdin);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i]=='9')
		{
			counter++;
		}
	}
	if (counter == 0) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	return 0;
}
