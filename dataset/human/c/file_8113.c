#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int i;
	int a, b, c, d;
	int s1, s2;
	char buf[128], *ch;

	fgets(buf, sizeof(buf), stdin);
	ch = strtok(buf, " ");
	a = atoi(ch);
	ch = strtok(NULL, " ");
	b = atoi(ch);
	ch = strtok(NULL, " ");
	c = atoi(ch);
	ch = strtok(NULL, " ");
	d = atoi(ch);

	s1 = a * b;
	s2 = c * d;

	if(s1 > s2) {
		printf("%d\n", s1);
	} else {
		printf("%d\n", s2);
	}

	return 0;
}
