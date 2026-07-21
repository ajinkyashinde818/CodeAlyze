#include <stdio.h>
using namespace std;
int n, m;
char a[55][55], b[55][55];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", a[i]+1);
	for (int i = 1; i <= m; i++) scanf("%s", b[i]+1);
	for (int sx = 1; sx <= n - m + 1; sx++)
		for (int sy = 1; sy <= n - m + 1; sy++) {
			bool f = true;
			for (int i = sx; i <= sx + m - 1; i++)
				for (int j = sy; j <= sy + m - 1; j++)
					if (a[i][j] != b[i-sx+1][j-sy+1]) f = false;
			if (f) {
				printf("Yes\n");
				return 0;
			}
		}
	printf("No\n");
	return 0;
}
