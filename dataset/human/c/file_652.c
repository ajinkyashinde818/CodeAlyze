#include<stdio.h>

char pic_a[55][55],pic_b[55][55];
int N, M;

int check(int x, int y) {
	int i, j;
	int flag=0;
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {		
			if (x + i < N && y + j < N) {
				if (pic_b[i][j] != pic_a[x + i][y + j]) 
					return 0;
			}
			else
				return 0;
		}
	}
	return 1;
}

int main(void) {
	int i, j,result=0;

	scanf("%d %d",&N,&M);
	for (i = 0; i < N; i++) 
			scanf("%s",pic_a[i]);
	for (i = 0; i < M; i++)
		scanf("%s", pic_b[i]);


	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (pic_b[0][0] == pic_a[i][j]) {
				result = check(i,j);
				if (result)break;
			}
		}
		if (result)break;
	}
	if (result)printf("Yes\n");
	else printf("No\n");
	return 0;
}
