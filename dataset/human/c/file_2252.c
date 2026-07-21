// AOJ Volume 0 Problem 0092

#include <stdio.h>
#include <string.h>

#define SIZE (1000)

int map[SIZE][SIZE];
int indexx[SIZE + 1][SIZE + 1][2];

int main(void)
{
	int n;
	char str[1001];
	int i, j;
	int max;
	int s;
	

    while (1){
		scanf("%d", &n);
		if (n == 0){
			break;
		}
		for (i = 0; i < n; i++){
			scanf("%s", str);
			for (j = 0; str[j] != '\0'; j++){
				if (str[j] == '*'){
					map[i][j] = 0;
				}
				else {
					map[i][j] = 1;
				}
			}
		}
		
		memset(indexx, 0, sizeof(indexx));
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (j == 0){
					indexx[i][j][0] = map[i][j];
					indexx[j][i][1] = map[j][i];
				}
				else {
					indexx[i][j][0] = (indexx[i][j - 1][0] + map[i][j]) * map[i][j];
					indexx[j][i][1] = (indexx[j - 1][i][1] + map[j][i]) * map[j][i];
				}
			}
		}
//		for (i = 0; i < n; i++){
//			for (j = 0; j < n; j++){
//				printf("(%2d:%2d)", index[i][j][0], index[i][j][1]);
//			}
//			printf("\n");
//		}
		max = 0;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (indexx[i][j][0] != 0 && indexx[i][j][1] != 0){
					s = 2;
					while (indexx[i + s - 1][j + s - 1][0] >= s && indexx[i + s - 1][j + s - 1][1] >= s){
						s++;
					}
					s--;
					if (s > max){
//						printf("<%d, %d=%d>", j, i, s);
						max = s;
					}
				}
			}
		}
		
		printf("%d\n", max);
	}
	return (0);
}
