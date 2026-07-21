#include<stdio.h>
int main(void){
	char str[55] = "\0";
	int j = 0, k = 0;
	scanf("%s", str);
	for (int i = 0; i < 54; i++){
		j = i;
		if (str[i] == '\0')
			break;
	}
	for (int i = 0; i < j - 8; i++)
		printf("%c", str[i]);
	printf("\n");
	return 0;
}
