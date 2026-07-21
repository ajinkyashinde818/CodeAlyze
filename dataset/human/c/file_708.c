#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int i, j, k ,l;
	int N, M;
	int result;
	int kl_break;
	char **a, **b;
	char buf[128], *ch;

	fgets(buf, sizeof(buf), stdin);
	ch = strtok(buf, " ");
	N = atoi(ch);
	ch = strtok(NULL, " ");
	M = atoi(ch);

	a = (char **)calloc(N, sizeof(char *));
	for(i = 0; i < N; i += 1) {
		a[i] = (char *)calloc(64, sizeof(char *));
	}
	b = (char **)calloc(N, sizeof(char *));
	for(i = 0; i < M; i += 1) {
		b[i] = (char *)calloc(64, sizeof(char *));
	}

	for(i = 0; i < N; i += 1) {
		fgets(a[i], sizeof(buf), stdin);
	}
	for(i = 0; i < M; i += 1) {
		fgets(b[i], sizeof(buf), stdin);
	}

	result = 0;
	for(i = 0; i < N - M + 1; i += 1) {
		for(j = 0; j < N - M + 1; j += 1) {
			kl_break = 0;
			//bの左上はaのi,jにある
			for(k = 0; k < M; k += 1) {//bと(aの一部)の一致を調べる
				for(l = 0; l < M; l += 1) {//bと(aの一部)の一致を調べる
					if(a[i + l][j + k] != b[l][k]) {
						kl_break = 1;
						break;//if 1 pixel different exit kl loop
					}
				}
				if(kl_break == 1) {//if 1 pixel different exit kl loop
					break;
				}
			}
			if(kl_break == 0) {//if all pixels same in kl loop exit ij loop
				result = 1;
				break;
			}
		}
		if(result == 1) {
			break;
		}
	}

	if(result == 1) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	for(i = 0; i < N; i += 1) {
		free(a[i]);
	}
	free(a);
	for(i = 0; i < M; i += 1) {
		free(b[i]);
	}
	free(b);

	return 0;
}
