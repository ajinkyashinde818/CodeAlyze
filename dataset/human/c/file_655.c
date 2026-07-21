#include<stdio.h>
#include<string.h>

char a[51][51];
char b[51][51];

int main(void) {

	int i, j, k, l;
	int n, m;
	int flag = 0;
	char c;

	scanf("%d%d%c", &n, &m, &c);

	//行列のnまたはm成分には改行文字が含まれていることに注意//
	for (i = 0; i < n; i++) {
		scanf("%s", a[i], 51);
	}

	for (i = 0; i < m; i++) {
		scanf("%s", b[i], 51);
	}


	//同じ行列が含まれるか判定//
	//まず大きいほうの各行列成分について//
	for (i = 0; i <= n - m; i++) {
		for (j = 0; j <= n - m; j++) {
			//小さいほうの各行列成分が等しいか確認//
			for (k = 0; k < m; k++) {
				for (l = 0; l < m; l++) {
					if (a[i + k][j + l] != b[k][l]) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					break;
				}
			}
			if (flag == 0) {
				printf("Yes\n");
				return 0;
			}
			flag = 0;
		}
	}

	printf("No\n");
	   
	return 0;
}
