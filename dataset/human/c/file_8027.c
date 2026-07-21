#include <stdio.h>

int main()
{
	int i, H, W, C[2], D[2];
	char S[1010][1010] = {};
	scanf("%d %d", &H, &W);
	scanf("%d %d", &(C[0]), &(C[1]));
	scanf("%d %d", &(D[0]), &(D[1]));
	for (i = 5; i < H + 5; i++) scanf("%s", &(S[i][5]));
	
	short q[5000001][2];
	int j, k, l, dist[1010][1010], head, tail;
	for (i = 5; i < H + 5; i++) {
		for (j = 5; j < W + 5; j++) dist[i][j] = 1000000;
	}
	dist[C[0]+4][C[1]+4] = 0;
	q[2500000][0] = C[0] + 4;
	q[2500000][1] = C[1] + 4;
	for (head = 2500000, tail = 2500001; head < tail; head++) {
		i = q[head][0];
		j = q[head][1];
		
		if (S[i-1][j] == '.' && dist[i-1][j] > dist[i][j]) {
			dist[i-1][j] = dist[i][j];
			q[head][0] = i - 1;
			q[head--][1] = j;
		}
		if (S[i+1][j] == '.' && dist[i+1][j] > dist[i][j]) {
			dist[i+1][j] = dist[i][j];
			q[head][0] = i + 1;
			q[head--][1] = j;
		}
		if (S[i][j-1] == '.' && dist[i][j-1] > dist[i][j]) {
			dist[i][j-1] = dist[i][j];
			q[head][0] = i;
			q[head--][1] = j - 1;
		}
		if (S[i][j+1] == '.' && dist[i][j+1] > dist[i][j]) {
			dist[i][j+1] = dist[i][j];
			q[head][0] = i;
			q[head--][1] = j + 1;
		}

		for (k = i - 2; k <= i + 2; k++) {
			for (l = j - 2; l <= j + 2; l++) {
				if (S[k][l] == '.' && dist[k][l] > dist[i][j] + 1) {
					dist[k][l] = dist[i][j] + 1;
					q[tail][0] = k;
					q[tail++][1] = l;
				}
			}
		}
	}
	
	if (dist[D[0]+4][D[1]+4] < 1000000) printf("%d\n", dist[D[0]+4][D[1]+4]);
	else printf("-1\n");
	fflush(stdout);
	return 0;
}
