#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int i;
	char buf[128], *ch;

	fgets(buf, sizeof(buf), stdin);
	ch = strtok(buf, " ");
	i = atoi(ch);

	if(i < 1200) {
		printf("ABC\n");
	} else {
		printf("ARC\n");
	}

	return 0;
}
