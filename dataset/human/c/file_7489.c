#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char **input;
	int i, j;
	
	input = (char **)malloc(sizeof(char *) * 50000);
	for (j = 0; j <= 49999; j++){
		input[j] = (char *)malloc(sizeof(char) * 6);
	}
	
	for (j = 0; j <= 49999; j++){
		fgets(input[j], sizeof(char) * 7, stdin);
		if ((atoi(input[j]) == 0)){
			break ;
		}
	}
	
	for (i = 0; i <= (j - 1); i++)
	printf("Case %d: %s", i + 1, input[i]);
	
	return 0;
}
