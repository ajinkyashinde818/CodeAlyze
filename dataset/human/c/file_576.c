#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;
	int m = 0;

	scanf("%d", &n);
	scanf("%d", &m);

	int a[51][51] = { -1 };
	int b[51][51] = { -1 };
	char tmp;


	//a読み込み部
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c", &tmp);
			if (tmp == '\n') { scanf("%c", &tmp); }
			if (tmp == '.') { a[i][j] = 0; }
			else if(tmp == '#'){ a[i][j] = 1; }

		}
	}

	//b読み込み部
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &tmp);
			if (tmp == '\n') { scanf("%c", &tmp); }

			if (tmp == '.') { b[i][j] = 0; }
			else if (tmp == '#') { b[i][j] = 1; }

		}
	}

	if (n - m < 0) {printf("No");	return 0;}

	int x = 0;
	int y = 0;

	for (int i = 0; i < n - m +1; i++) {
		for (int j = 0; j < n - m +1; j++) {

			for (x = 0; x < m; x++) {
				for (y = 0; y < m; y++) {
					if (a[i+x][j+y] != b[x][y]) { goto next; }
				}
				if (x == (m - 1) && y == (m) ) { printf("Yes"); 
				return 0; }
			}
			next:;

		}
	}

	printf("No");

	return 0;
}
