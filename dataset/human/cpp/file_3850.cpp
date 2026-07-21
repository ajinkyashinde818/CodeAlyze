#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const int MAXN = 1000 + 10;

int n;
double x[MAXN], y[MAXN], r[MAXN];
double dis[MAXN];
bool vis[MAXN];

inline double calcdis(int i, int j) { return sqrt((y[i] - y[j]) * (y[i] - y[j]) + (x[i] - x[j]) * (x[i] - x[j])); }
inline double calc(int i, int j) { return std::max(0.0, calcdis(i, j) - r[i] - r[j]); }

int main() {
	int i, j, k;
	
	scanf("%lf %lf %lf %lf", &x[1], &y[1], &x[2], &y[2]);
	scanf("%d", &n);
	n += 2;
	for(i=3; i<=n; i++) 
		scanf("%lf %lf %lf", &x[i], &y[i], &r[i]);

	memset(dis, 0x7f, sizeof(dis));
	dis[1] = 0;
	for(i=1; i<n; i++) {
		k = 0;
		for(j=1; j<=n; j++)	
			if(!vis[j] and dis[j] < dis[k])
				k = j;
		
		vis[k] = true;
		for(j=1; j<=n; j++)
			dis[j] = std::min(dis[j], dis[k] + calc(j, k));
	}
	printf("%.10lf\n", dis[2]);
	return 0;
}
