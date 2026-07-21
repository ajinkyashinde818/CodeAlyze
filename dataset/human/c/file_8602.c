#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int i;
	int N;
	int *a;
	int light;
	char buf[128], *ch;

	fgets(buf, sizeof(buf), stdin);
	ch = strtok(buf, " ");
	N = atoi(ch);

	a = (int *)calloc(N, sizeof(int));

	for(i = 0; i < N; i += 1){
		fgets(buf, sizeof(buf), stdin);
		ch = strtok(buf, " ");
		a[i] = atoi(ch);
	}
	light = 0;
	for(i = 1; i <= N; i += 1){
		light = a[light] - 1;
		if(light == 1) {
			break;
		}
	}
	if(light == 1) {
		printf("%d\n", i);
	} else {
		printf("-1\n");
	}

	free(a);
	return 0;
}
