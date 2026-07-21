#include <stdio.h>
#include <math.h>

int main()
{
	int i, N, s[2], t[2], x[1001], y[1001], r[1002];
	scanf("%d %d %d %d", &(s[0]), &(s[1]), &(t[0]), &(t[1]));
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d %d", &(x[i]), &(y[i]), &(r[i]));
	
	int j;
	long double tmp, time[1002][1002] = {};
	for (i = 1; i < N; i++) {
		for (j = i + 1; j <= N; j++) {
			tmp = sqrt((long double)(x[i] - x[j]) * (x[i] - x[j]) + (long double)(y[i] - y[j]) * (y[i] - y[j]));
			if (tmp < (long double)(r[i] + r[j])) tmp = 0.0;
			else tmp -= (long double)(r[i] + r[j]);
			time[i][j] = tmp;
			time[j][i] = tmp;
		}
	}
	for (i = 1; i <= N; i++) {
		tmp = sqrt((long double)(x[i] - s[0]) * (x[i] - s[0]) + (long double)(y[i] - s[1]) * (y[i] - s[1]));
		if (tmp < (long double)r[i]) tmp = 0.0;
		else tmp -= (long double)r[i];
		time[i][0] = tmp;
		time[0][i] = tmp;
		tmp = sqrt((long double)(x[i] - t[0]) * (x[i] - t[0]) + (long double)(y[i] - t[1]) * (y[i] - t[1]));
		if (tmp < (long double)r[i]) tmp = 0.0;
		else tmp -= (long double)r[i];
		time[i][N+1] = tmp;
		time[N+1][i] = tmp;
	}
	time[0][N+1] = sqrt((long double)(s[0] - t[0]) * (s[0] - t[0]) + (long double)(s[1] - t[1]) * (s[1] - t[1]));
	time[N+1][0] = time[0][N+1];
	
	int u, w, flag[1002] = {};
	long double min[1002];
	for (i = 1, min[0] = 0.0; i <= N + 1; i++) min[i] = 1e+100;
	while (flag[N+1] == 0) {
		for (u = 0, tmp = 1e+100; u <= N + 1; u++) {
			if (flag[u] == 0 && min[u] < tmp) {
				tmp = min[u];
				w = u;
			}
		}
		flag[w] = 1;
		for (u = w, w = 1; w <= N + 1; w++) {
			if (min[u] + time[u][w] < min[w]) min[w] = min[u] + time[u][w];
		}
	}
	
	printf("%.10Lf\n", min[N+1]);
	fflush(stdout);
	return 0;
}
