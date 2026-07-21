#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
#ifdef DEBUG
	printf("");
#endif

	int N, M;
	int tmp1, tmp2;
	char hatu[200000];
	char tyaku[200000];
	int i;

	memset(hatu, '0', sizeof(hatu));
	memset(tyaku, '0', sizeof(tyaku));

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d", &tmp1 ,&tmp2);

#ifdef DEBUG
		printf("tmp1=%d, tmp2=%d\n", tmp1, tmp2);
#endif
		if (tmp1 == 1) {
			hatu[tmp2-1] = '1';
		}
		else if(tmp2==N){
			tyaku[tmp1-1] = '1';
		}
	}

	for (i = 0; i < M; i++) {
#ifdef DEBUG
		printf("hatu[%d]=%c, tyaku[%d]=%c\n", i, hatu[i], i, tyaku[i]);
#endif
		if (hatu[i] == '1' && tyaku[i] == '1') {
			printf("POSSIBLE\n");
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");
}
