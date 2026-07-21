#include <stdio.h>

char img[50][50];
char temp[50][50];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &img[j][i]);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &temp[j][i]);
		}
	}
	bool ret = false;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			bool f = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (temp[l][k] != img[j + l][i + k]) {
						f = false;
						goto NEXT;
					}
				}
			}
		NEXT:
			if (f) {
				ret = true;
				goto END;
			}
		}
	}
END:
	if (ret) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
