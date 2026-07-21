#include<stdio.h>
#include<string.h>
#pragma warning (disable : 4996)

int main() {

	int input;
	scanf("%d", &input);
	
	char kata[4];
	sprintf(kata, "%d", input);
	for (int i = 0; i < strlen(kata); i++) {
		if (kata[i] == '9') {
			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");
	return 0;
}
