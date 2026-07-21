#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int i;
	int s;
	int N;
	int *D;
	char buf[128], *ch;

	fgets(buf, sizeof(buf), stdin);
	ch = strtok(buf, " ");
	N = atoi(ch);
	D = (int *)calloc(N, sizeof(int));
	for(i = 0; i < N; i += 1) {
		fgets(buf, sizeof(buf), stdin);
		ch = strtok(buf, " ");
		D[2 * i] = atoi(ch);
		ch = strtok(NULL, " ");
		D[2 * i + 1] = atoi(ch);
	}

	s = 0;
	for(i = 0; i < N; i += 1) {
		if(s == 3) {
			break;
		}
		if(D[2 * i] == D[2 * i + 1]) {
			s += 1;
		} else {
			s = 0;
		}
	}
	if(s == 3) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	free(D);
	return 0;
}
