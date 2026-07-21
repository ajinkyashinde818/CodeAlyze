#include<stdio.h>

int main() {
	bool x[500][500]{};
	bool y[500]{};
	y[0] = true;
	int n, m, a, b, cnt = 0;
	scanf("%d%d", &n, &m);
	if (!(n | m))return 0;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		a--; b--; x[a][b] = true; x[b][a] = true;
		if (!a){ cnt++; y[b] = true;}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (x[0][i] && x[i][j] && !y[j]){ cnt++; y[j] = true; }
	printf("%d\n", cnt);
	main();
}
