#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int N, M;
	char buffer[128];
	char *ch;

	fgets(buffer, sizeof(buffer), stdin);
	ch = strtok(buffer, " ");
	N = atoi(ch);
	ch = strtok(NULL, " ");
	M = atoi(ch);

	if(N == M) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}


	return 0;
}
